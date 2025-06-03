/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** compute_sprite_size
*/

#include <SFML/System/Vector2.h>

sfVector2f compute_sprite_size(sfVector2u tex_size, float scale)
{
    return (sfVector2f){tex_size.x * scale, tex_size.y * scale};
}
