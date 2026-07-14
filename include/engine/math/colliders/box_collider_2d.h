#ifndef ENGINE_BOX_COLLIDER_H
#define ENGINE_BOX_COLLIDER_H
#include "collider.h"
#include "vector3.h"

typedef struct box_collider_2d
{
    Collider base;
    Vector3 position;
    Vector3 size;
} BoxCollider2D;

bool collider_intersects(const BoxCollider2D *a, const BoxCollider2D *b,
    const Vector3 *rotation_a, const Vector3 *rotation_b);

#endif /* ENGINE_BOX_COLLIDER_H */