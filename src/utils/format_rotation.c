/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** format_rotation
*/

#include <math.h>

double format_rotation(double rotation)
{
    while (rotation < 0) {
        rotation += M_PI * 2;
    }
    while (rotation >= M_PI * 2) {
        rotation -= M_PI * 2;
    }
    return rotation;
}
