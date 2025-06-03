/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** compute_angle
*/

#include "utils.h"

float compute_angle(sfVector2f a, sfVector2f b)
{
    float dot = a.x * b.x + a.y * b.y;
    float det = a.x * b.y - a.y * b.x;

    return atan2f(det, dot) * (180.0f / M_PI);
}
