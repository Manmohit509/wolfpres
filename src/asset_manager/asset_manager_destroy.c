/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** asset_manager_destroy
*/

#include <stdlib.h>

#include "asset_manager.h"

static void free_texture_asset(void *ptr)
{
    texture_asset_t *asset = ptr;

    if (!asset)
        return;
    if (asset->texture)
        sfTexture_destroy(asset->texture);
    free(asset->id);
    free(asset);
}

static void free_entity_asset(void *ptr)
{
    entity_asset_t *asset = ptr;

    if (!asset)
        return;
    if (asset->texture)
        sfTexture_destroy(asset->texture);
    free(asset->id);
    free(asset);
}

static void free_sound_asset(void *ptr)
{
    sound_asset_t *asset = ptr;

    if (!asset)
        return;
    if (asset->buffer)
        sfSoundBuffer_destroy(asset->buffer);
    free(asset->id);
    free(asset);
}

static void free_shader_asset(void *ptr)
{
    shader_asset_t *asset = ptr;

    if (!asset)
        return;
    if (asset->shader)
        sfShader_destroy(asset->shader);
    free(asset->id);
    free(asset);
}

static void free_font_asset(void *ptr)
{
    font_asset_t *asset = ptr;

    if (!asset)
        return;
    if (asset->font) {
        sfFont_destroy(asset->font);
    }
    free(asset->id);
    free(asset);
}

static void free_musics_asset(void *ptr)
{
    music_asset_t *asset = ptr;

    if (!asset)
        return;
    if (asset->music) {
        sfMusic_destroy(asset->music);
    }
    free(asset->id);
    free(asset);
}

void asset_manager_destroy(asset_manager_t *manager)
{
    if (!manager)
        return;
    if (manager->textures)
        hashmap_destroy(manager->textures, &free_texture_asset);
    if (manager->entities)
        hashmap_destroy(manager->entities, &free_entity_asset);
    if (manager->sounds)
        hashmap_destroy(manager->sounds, &free_sound_asset);
    if (manager->shaders)
        hashmap_destroy(manager->shaders, &free_shader_asset);
    if (manager->fonts)
        hashmap_destroy(manager->fonts, &free_font_asset);
    if (manager->musics)
        hashmap_destroy(manager->musics, &free_musics_asset);
    free(manager);
}
