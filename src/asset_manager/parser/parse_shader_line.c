/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** parse_shader_line
*/

#include <stdlib.h>
#include <string.h>

#include "asset_manager.h"
#include "utils.h"

void parse_shader_line(
    asset_manager_t *manager,
    FILE *file,
    const char *asset_path)
{
    char id[64] = {0};
    char path[256] = {0};
    char full_path[512] = {0};
    sfShader *shader = NULL;
    shader_asset_t *asset = NULL;

    if (fscanf(file, "%63s %255s", id, path) != 2)
        return;
    snprintf(full_path, sizeof(full_path), "%s%s", asset_path, path);
    shader = sfShader_createFromFile(NULL, NULL, full_path);
    if (!shader) {
        log_warn("Shader loading failed: %s\n", full_path);
        return;
    }
    asset = malloc(sizeof(shader_asset_t));
    if (!asset)
        return;
    asset->id = strdup(id);
    asset->shader = shader;
    hashmap_insert(manager->shaders, asset->id, asset);
}
