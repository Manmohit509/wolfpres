/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** vector2f_to_angle
*/

#include <math.h>

#include "utils.h"

float vector2f_to_angle(sfVector2f direction)
{
    return atan2f(direction.y, direction.x);
}
