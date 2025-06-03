/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** compute_distance
*/

#include <math.h>
#include <SFML/System/Vector2.h>


float compute_distance(sfVector2f a, sfVector2f b)
{
    return sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
