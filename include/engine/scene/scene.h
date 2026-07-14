#ifndef ENGINE_SCENE_H
#define ENGINE_SCENE_H

#include <stdint.h>
#include "project.h"
#include "engine/entity/entity.h"
#include "engine/entity/components/component.h"

typedef struct Scene
{
    // Entity manager to handle entity creation and destruction
    EntityManager entities;
    // Array to store component masks for each entity
    uint32_t component_masks[MAX_ENTITIES];
    // Storage for components associated with entities
    EntitiesComponentsArray components_storage;
    // Pointer to the components array for easy access
    EntitiesComponentsArray *components_array;
} Scene;

void scene_init(Scene *scene);
void scene_destroy(Scene *scene);
/// @brief Changes the value of a component associated with an entity in the scene.
/// @param scene The scene containing the entity and its components.
/// @param entity The entity whose component value is to be changed.
/// @param component_name The name of the component whose value is to be changed.
/// @param data The new value to set for the component.
void change_component_value(Scene *scene, Entity entity, char *component_name, char *data);
char* get_component_value(const Scene *scene, Entity entity, const char *component_name);
void create_component(Scene *scene, Entity entity, const char *component_name, char *initial_value);

#endif /* ENGINE_SCENE_H */