#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include <stdbool.h>
#include <stdint.h>
#include "project.h"

typedef uint32_t Entity;

typedef struct
{
	bool alive[MAX_ENTITIES];
	Entity free_list[MAX_ENTITIES];
	uint32_t free_count;
} EntityManager;

typedef struct Scene Scene;

#define INVALID_ENTITY UINT32_MAX

void entity_manager_init(EntityManager *manager);
Entity entity_create(Scene *scene);
void entity_destroy(Scene *scene, Entity entity);
bool has_components(Scene *scene, Entity entity, uint32_t required_mask);

#endif /* ENGINE_ENTITY_H */
