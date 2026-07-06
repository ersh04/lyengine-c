#include <stdbool.h>
#include <string.h>
#include "engine/entity/entity.h"
#include "engine/scene/scene.h"

/// @brief Manages the initialization of the entity manager by setting all
/// entities to dead and populating the free list with available entity IDs.
/// @param manager The entity manager to initialize.
void entity_manager_init(EntityManager *manager)
{
    manager->free_count = MAX_ENTITIES;

    for (uint32_t i = 0; i < MAX_ENTITIES; i++)
    {
        manager->alive[i] = false;
        manager->free_list[i] = i;
    }
}

/// @brief Creates a new entity and returns its ID.
/// @param scene The scene in which to create the entity.
/// @return The ID of the newly created entity, or INVALID_ENTITY if no entities are available.
Entity entity_create(Scene *scene)
{
    EntityManager *manager = &scene->entities;

    if (manager->free_count == 0)
        return INVALID_ENTITY;

    Entity entity = manager->free_list[--manager->free_count];

    manager->alive[entity] = true;
    scene->component_masks[entity] = 0;

    return entity;
}

/// @brief Destroys an entity and marks it as dead.
/// @param scene The scene in which the entity exists.
/// @param entity The entity to destroy.
void entity_destroy(Scene *scene, Entity entity)
{
    EntityManager *manager = &scene->entities;

    if (entity >= MAX_ENTITIES || !manager->alive[entity])
        return;

    manager->alive[entity] = false;
    scene->component_masks[entity] = 0;

    manager->free_list[manager->free_count++] = entity;
}

/// @brief Checks if an entity has the required components.
/// @param scene The scene in which the entity exists.
/// @param entity The entity to check.
/// @param required_mask The mask of required components.
/// @return true if the entity has all the required components, false otherwise.
bool has_components(Scene *scene, Entity entity, uint32_t required_mask)
{
    if (scene == NULL || entity >= MAX_ENTITIES)
        return false;

    return scene->entities.alive[entity] &&
           (scene->component_masks[entity] & required_mask) == required_mask;
}
