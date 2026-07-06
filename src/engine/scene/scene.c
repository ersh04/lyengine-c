#include <string.h>
#include "engine/scene/scene.h"

void scene_init(Scene *scene)
{
    memset(scene, 0, sizeof(*scene));
    // Initialize the components array to point to the storage
    scene->components_array = &scene->components_storage;
    entity_manager_init(&scene->entities);
}

void change_component_value(Scene *scene, Entity entity, char* component_name, float value)
{
    if (scene == NULL || entity >= MAX_ENTITIES || !scene->entities.alive[entity])
        return;
    
    for (int i = 0; i < MAX_COMPONENTS_PER_ENTITY; i++)
    {
        if (scene->components_array->component_names[i] != NULL &&
                strcmp(scene->components_array->component_names[i], component_name) == 0)
        {
            scene->components_array->component_data[i] = value;
            break;
        }
    }
}

float get_component_value(const Scene *scene, Entity entity, const char *component_name)
{
    if (scene == NULL || component_name == NULL || entity >= MAX_ENTITIES || !scene->entities.alive[entity])
        return 0.0f;

    for (int i = 0; i < MAX_COMPONENTS_PER_ENTITY; i++)
    {
        if (scene->components_array->component_names[i] != NULL &&
            strcmp(scene->components_array->component_names[i], component_name) == 0)
        {
            return scene->components_array->component_data[i];
        }
    }

    return 0.0f;
}

void create_component(Scene *scene, Entity entity, const char *component_name, float initial_value)
{
    if (scene == NULL || component_name == NULL || entity >= MAX_ENTITIES || !scene->entities.alive[entity])
        return;

    for (int i = 0; i < MAX_COMPONENTS_PER_ENTITY; i++)
    {
        if (scene->components_array->component_names[i] == NULL)
        {
            scene->components_array->component_names[i] = (char *)component_name;
            scene->components_array->component_data[i] = initial_value;
            scene->component_masks[entity] |= (1u << i);
            break;
        }
    }
}