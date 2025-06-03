/*
** EPITECH PROJECT, 2025
** Gwolf
** File description:
** listeners
*/

#ifndef LISTENERS_H
    #define LISTENERS_H

    #include "process.h"

void handle_movements(sfEvent *event, process_t *process);
void ingame_interaction_listener(sfEvent *event, process_t *process);


#endif /* LISTENERS_H */