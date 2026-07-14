#include <string.h>
#include <stdlib.h>
#include "engine/scene/scene.h"

static char *duplicate_string(const char *value)
{
    if (value == NULL)
        return NULL;

    size_t length = strlen(value) + 1;
    char *copy = malloc(length);

    if (copy != NULL)
        memcpy(copy, value, length);

    return copy;
}

void scene_init(Scene *scene)
{
    memset(scene, 0, sizeof(*scene));
    // Initialize the components array to point to the storage
    scene->components_array = &scene->components_storage;
    entity_manager_init(&scene->entities);
}

void scene_destroy(Scene *scene)
{
    if (scene == NULL)
        return;

    for (int i = 0; i < MAX_COMPONENTS_PER_ENTITY; i++)
    {
        free(scene->components_array->component_data[i]);
        scene->components_array->component_data[i] = NULL;
    }
}

void change_component_value(Scene *scene, Entity entity, char *component_name, char *value)
{
    if (scene == NULL || component_name == NULL || entity >= MAX_ENTITIES || !scene->entities.alive[entity])
        return;
    
    for (int i = 0; i < MAX_COMPONENTS_PER_ENTITY; i++)
    {
        if (scene->components_array->component_names[i] != NULL &&
                strcmp(scene->components_array->component_names[i], component_name) == 0)
        {
            char *new_value = duplicate_string(value);

            if (value != NULL && new_value == NULL)
                return;

            free(scene->components_array->component_data[i]);
            scene->components_array->component_data[i] = new_value;
            break;
        }
    }
}

char* get_component_value(const Scene *scene, Entity entity, const char *component_name)
{
    if (scene == NULL || component_name == NULL || entity >= MAX_ENTITIES || !scene->entities.alive[entity])
        return NULL;

    for (int i = 0; i < MAX_COMPONENTS_PER_ENTITY; i++)
    {
        if (scene->components_array->component_names[i] != NULL &&
            strcmp(scene->components_array->component_names[i], component_name) == 0)
        {
            return scene->components_array->component_data[i];
        }
    }

    return NULL;
}

void create_component(Scene *scene, Entity entity, const char *component_name, char *initial_value)
{
    if (scene == NULL || component_name == NULL || entity >= MAX_ENTITIES || !scene->entities.alive[entity])
        return;

    for (int i = 0; i < MAX_COMPONENTS_PER_ENTITY; i++)
    {
        if (scene->components_array->component_names[i] == NULL)
        {
            char *initial_value_copy = duplicate_string(initial_value);

            if (initial_value != NULL && initial_value_copy == NULL)
                return;

            scene->components_array->component_names[i] = (char *)component_name;
            scene->components_array->component_data[i] = initial_value_copy;
            scene->component_masks[entity] |= (1u << i);
            break;
        }
    }
}