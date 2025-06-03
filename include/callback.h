/*
** EPITECH PROJECT, 2025
** Jofrenstein3D
** File description:
** callback
*/

#ifndef CALLBACK_H
    #define CALLBACK_H

void exit_callback(void *userdata);
void singleplayer_callback(void *userdata);
void go_back_callback(void *userdata);
void load_game_callback(void *userdata);
void multiplayer_callback(void *userdata);
void create_game_callback(void *userdata);
void world_name_callback(const char *text, void *userdata);
void settings_callback(void *userdata);
void graphical_enum_selector_callback(
    const char *value,
    int index,
    void *userdata);
void musics_slider_callback(float value, void *user_data);
void sounds_slider_callback(float value, void *user_data);
void sensibility_slider_callback(float value, void *user_data);

#endif /* CALLBACK_H */
