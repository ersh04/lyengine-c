#include "box_collider_2d.h"
#include <math.h>

/// @brief Checks if two 2D box colliders intersect, taking their rotations into account.
/// @param a The first box collider.
/// @param b The second box collider.
/// @param rotation_a The rotation of the first box collider.
/// @param rotation_b The rotation of the second box collider.
/// @return True if the colliders intersect, false otherwise.
bool collider_intersects(const BoxCollider2D *a, const BoxCollider2D *b,
        const Vector3 *rotation_a, const Vector3 *rotation_b)
{
    Vector2 rotated_a = rotate_point(&a->position.base, &a->position.base, rotation_a->z);
    Vector2 rotated_b = rotate_point(&b->position.base, &b->position.base, rotation_b->z);

    return (rotated_a.x < rotated_b.x + b->size.base.x &&
        rotated_a.x + a->size.base.x > rotated_b.x &&
        rotated_a.y < rotated_b.y + b->size.base.y &&
        rotated_a.y + a->size.base.y > rotated_b.y);
}

/// @brief Rotates a point around a given origin by a specified angle.
/// @param point The point to rotate.
/// @param origin The origin to rotate around.
/// @param angle The angle to rotate by, in radians.
/// @return The rotated point.
Vector2 rotate_point(const Vector2 *point, const Vector2 *origin, float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);

    // Translate point back to origin
    float translated_x = point->x - origin->x;
    float translated_y = point->y - origin->y;

    // Rotate point
    float rotated_x = translated_x * c - translated_y * s;
    float rotated_y = translated_x * s + translated_y * c;

    // Translate point back
    Vector2 result;
    result.x = rotated_x + origin->x;
    result.y = rotated_y + origin->y;

    return result;
}