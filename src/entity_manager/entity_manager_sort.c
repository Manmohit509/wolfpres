/*
** EPITECH PROJECT, 2025
** Gwolf
** File description:
** entity_manager_sort
*/

#include <stdlib.h>

#include "entity_manager.h"

static float distance_squared(sfVector2f a, sfVector2f b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return dx * dx + dy * dy;
}

static size_t count_entities(entity_node_t *head)
{
    size_t count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

static sfVector2f sort_origin;

static int compare_nodes_desc(const void *a, const void *b)
{
    const entity_node_t *node_a = *(const entity_node_t **)a;
    const entity_node_t *node_b = *(const entity_node_t **)b;

    float da = distance_squared(node_a->entity.pos, sort_origin);
    float db = distance_squared(node_b->entity.pos, sort_origin);

    if (da < db) return 1;
    if (da > db) return -1;
    return 0;
}

void entity_manager_sort(entity_manager_t *manager, sfVector2f pos)
{
    if (!manager || !manager->head)
        return;

    size_t count = count_entities(manager->head);
    if (count == 0)
        return;

    entity_node_t **node_array = malloc(sizeof(entity_node_t *) * count);
    if (!node_array)
        return;

    entity_node_t *current = manager->head;
    for (size_t i = 0; i < count && current; i++, current = current->next) {
        node_array[i] = current;
    }

    sort_origin = pos;
    qsort(node_array, count, sizeof(entity_node_t *), compare_nodes_desc);

    for (size_t i = 0; i < count - 1; i++) {
        node_array[i]->next = node_array[i + 1];
    }
    node_array[count - 1]->next = NULL;
    manager->head = node_array[0];

    free(node_array);
}
