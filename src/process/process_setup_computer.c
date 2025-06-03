/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-nathan.billiouw
** File description:
** process_setup_computer.c
*/

#include <stdlib.h>
#include <string.h>

#include "process.h"
#include "wolf3d.h"

static void init_textbox(jojo_computer_t *computer, process_t *process)
{
    computer->textBox = sfText_create();
    if (get_font(process, "font"))
        sfText_setFont(computer->textBox, get_font(process, "font"));
    sfText_setCharacterSize(computer->textBox, 24);
    sfText_setColor(computer->textBox, sfBlack);
}

jojo_computer_t *init_jojo_computer(process_t *process)
{
    jojo_computer_t *computer = malloc(sizeof(jojo_computer_t));

    if (!computer)
        return NULL;
    memset(computer->input_string, 0, sizeof(computer->input_string));
    memset(computer->display_string, 0, sizeof(computer->display_string));
    computer->pass_mdp = false;
    computer->started = false;
    init_textbox(computer, process);
    return computer;
}
