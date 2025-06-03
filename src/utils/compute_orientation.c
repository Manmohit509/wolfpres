/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** compute_orientation
*/

#include "utils.h"

sfVector2f compute_orientation(float angle)
{
    float rad = angle * (float)M_PI / 180.0f;

    return (sfVector2f){cosf(rad), sinf(rad)};
}
