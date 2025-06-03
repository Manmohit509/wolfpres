/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** interpolate
*/

#include <SFML/System/Vector2.h>

sfVector2f interpolate(sfVector2f a, sfVector2f b, float t)
{
    return (sfVector2f){
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t
    };
}
