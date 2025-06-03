/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** assets_manager
*/

#ifndef ASSET_MANAGER_H
    #define ASSET_MANAGER_H

    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <SFML/Audio.h>

    #include "hashmap.h"

    #define ASSET_MAPS_BUCKET_COUNT 15

typedef struct texture_asset_s {
    char *id;
    sfTexture *texture;
} texture_asset_t;

typedef struct texture_parse_data_s {
    const char *id;
    const char *path;
} texture_parse_data_t;

typedef struct entity_asset_s {
    char *id;
    sfTexture *texture;
    int face_count;
    int state_count;
    int height;
    int width;
} entity_asset_t;

typedef struct entity_parse_data_s {
    char *id;
    char *path;
    int width;
    int height;
    int face_count;
    int state_count;
} entity_parse_data_t;

typedef struct sound_parse_data_s {
    const char *id;
    const char *path;
} sound_parse_data_t;

typedef struct sound_asset_s {
    char *id;
    sfSoundBuffer *buffer;
} sound_asset_t;

typedef struct shader_asset_s {
    char *id;
    sfShader *shader;
} shader_asset_t;

typedef struct font_asset_s {
    char *id;
    sfFont *font;
} font_asset_t;

typedef struct music_asset_s {
    char *id;
    sfMusic *music;
} music_asset_t;

typedef struct asset_manager_s {
    hashmap_t *textures;
    hashmap_t *entities;
    hashmap_t *sounds;
    hashmap_t *shaders;
    hashmap_t *fonts;
    hashmap_t *musics;
} asset_manager_t;

typedef struct parsing_rule_s {
    char const *type;
    void (*parse)(
        asset_manager_t *manager,
        FILE *file,
        const char *asset_path);
} parsing_rule_t;

void parse_texture_line(
    asset_manager_t *manager,
    FILE *file,
    char const *asset_path);
void parse_sound_line(
    asset_manager_t *manager,
    FILE *file,
    const char *asset_path);
void parse_entity_line(
    asset_manager_t *manager,
    FILE *file,
    char const *asset_path);
void parse_shader_line(
    asset_manager_t *manager,
    FILE *file,
    const char *asset_path);
void parse_font_line(
    asset_manager_t *manager,
    FILE *file,
    const char *asset_path);
void parse_music_line(
    asset_manager_t *manager,
    FILE *file,
    const char *asset_path);

static parsing_rule_t const rules[] = {
    {"texture", &parse_texture_line},
    {"sound", &parse_sound_line},
    {"entity", &parse_entity_line},
    {"shader", &parse_shader_line},
    {"font", &parse_font_line},
    {"music", &parse_music_line},
    {NULL, NULL}
};

asset_manager_t *asset_manager_create(void);
void asset_manager_destroy(asset_manager_t *manager);

int asset_manager_load_textures_from_file(
    asset_manager_t *manager,
    FILE *file,
    char const *asset_path);

texture_asset_t *asset_manager_get_texture(
    asset_manager_t *manager,
    const char *id);

entity_asset_t *asset_manager_get_entity(
    asset_manager_t *manager,
    const char *id);

sound_asset_t *asset_manager_get_sound(
    asset_manager_t *manager,
    const char *id);

shader_asset_t *asset_manager_get_shader(
    asset_manager_t *manager,
    const char *id);

music_asset_t *asset_manager_get_music(
    asset_manager_t *manager,
    const char *id);

font_asset_t *asset_manager_get_font(
    asset_manager_t *manager,
    const char *id);

#endif /* ASSET_MANAGER_H */
