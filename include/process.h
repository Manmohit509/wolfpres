/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** process
*/

#ifndef PROCESS_H
    #define PROCESS_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include <SFML/Audio/Export.h>

    #include "asset_manager.h"
    #include "ui/app.h"
    #include "logger.h"
    #include "level.h"
    #include "viewer.h"
    #include "settings.h"

    #define LOGGER_FILE (stderr)
    #define LOGGER_LEVEL (LOG_LEVEL_DEBUG)
    #define WINDOW_NAME "Joffreystein3D"
    #define WINDOW_W 900
    #define WINDOW_H 600
    #define WINDOW_FRAMERATE 60
    #define COMP_WIN_DIST 0.3

typedef struct jojo_computer_s {
    sfText *textBox;
    sfEvent *event;
    char input_string[21];
    char display_string[21];
    bool pass_mdp;
    bool started;
} jojo_computer_t;

typedef struct game_clock_s {
    sfClock *clock;
    sfTime last_time;
    double delta_t;
} game_clock_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfRenderTexture *scene;
    sfVideoMode video_mode;
    sfUint32 style;
    const sfContextSettings* settings;
    bool is_fullscreen;
    sfVector2u init_screen;
    char *title;
    int framerate;
} window_t;

typedef struct key_inputs_s {
    bool left_key;
    bool right_key;
    bool forward_key;
    bool backward_key;
    bool escape;
    bool reload_key;
    bool shoot_key;
    bool escape_key;
} key_inputs_t;

typedef struct process_s {
    level_t *level;
    window_t window;
    logger_t *logger;
    game_clock_t clock;
    ui_app_t *app;
    entity_logic_t *entity_logic;
    key_inputs_t inputs;
    asset_manager_t *assets;
    settings_t settings;
    jojo_computer_t *computer;
} process_t;

int process_setup(process_t *process);

void process_cleanup(process_t *process);

int process_update_window(process_t *process);

void process_update_clock(process_t *process);

int process_set_window_fullscreen(process_t *process, bool is_fullscreen);

void process_render_roof_and_top(process_t *process);

void process_render_walls(process_t *process, viewer_t *viewer);

void process_render_entities(process_t *process, viewer_t *viewer);

int process_draw_flashlight(process_t *process, bool is_on);

void process_render(process_t *process, viewer_t *viewer, entity_t *entity);

void process_draw_scene_to_window(process_t *process, sfShader *shader);

void process_render_computer(sfRenderWindow *window, process_t *process);

jojo_computer_t *init_jojo_computer(process_t *process);

void process_render_player_interface(
    process_t *process,
    entity_t *player);

void process_render_weapon(
    process_t *process,
    entity_t *player,
    player_data_t *data);

#endif /* PROCESS_H */
