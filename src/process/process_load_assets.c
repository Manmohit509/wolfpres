/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** process_load_assets
*/

#include <stdio.h>
#include <string.h>

#include "process.h"
#include "wolf3d.h"
#include "utils.h"


static char *remove_last_path_element(char *dest, const char *path)
{
    size_t len = strlen(path);

    if (len == 0)
        return NULL;
    for (size_t i = len - 1; i > 0; i--) {
        if (dest[i] == '/') {
            dest[i + 1] = '\0';
            return dest;
        }
    }
    dest[0] = '\0';
    return dest;
}

int process_load_assets(process_t *process, char const *assets_file)
{
    FILE *file = fopen(assets_file, "r");
    char path_buffer[256] = {0};

    if (file == NULL) {
        log_error("[load_assets]: Impossible to open file %s", assets_file);
        return FAILURE_EXIT;
    }
    if (process->assets) {
        asset_manager_destroy(process->assets);
    }
    process->assets = asset_manager_create();
    if (!process->assets) {
        return FAILURE_EXIT;
    }
    if (asset_manager_load_textures_from_file(process->assets, file,
        remove_last_path_element(path_buffer, assets_file)) != SUCCESS_EXIT) {
        return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}
