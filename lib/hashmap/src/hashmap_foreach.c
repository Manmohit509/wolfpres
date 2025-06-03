/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** hashmap_foreach
*/

#include "hashmap.h"

void hashmap_foreach(
    hashmap_t *map,
    void (*func)(const char *key, void *value, void *userdata),
    void *userdata)
{
    hashmap_entry_t *entry = NULL;

    if (!map || !func)
        return;
    for (size_t i = 0; i < map->bucket_count; ++i) {
        entry = map->buckets[i];
        while (entry) {
            func(entry->key, entry->value, userdata);
            entry = entry->next;
        }
    }
}
