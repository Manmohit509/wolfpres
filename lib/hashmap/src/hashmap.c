/*
** EPITECH PROJECT, 2025
** wolf3d-ref
** File description:
** hashmap
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashmap.h"

static unsigned long hash_string(const char *str, size_t bucket_count)
{
    unsigned long hash = 5381;

    for (size_t i = 0; str[i] != '\0'; i++) {
        hash = ((hash << 5) + hash) + (unsigned char) str[i];
    }
    return hash % bucket_count;
}

hashmap_t *hashmap_create(size_t bucket_count)
{
    hashmap_t *map = malloc(sizeof(hashmap_t));

    if (!map)
        return NULL;
    map->buckets = calloc(bucket_count, sizeof(hashmap_entry_t *));
    if (!map->buckets) {
        free(map);
        return NULL;
    }
    map->bucket_count = bucket_count;
    return map;
}

void hashmap_insert(hashmap_t *map, const char *key, void *value)
{
    unsigned long index = hash_string(key, map->bucket_count);
    hashmap_entry_t *entry = malloc(sizeof(hashmap_entry_t));

    if (!entry) {
        return;
    }
    entry->key = strdup(key);
    entry->value = value;
    entry->next = map->buckets[index];
    map->buckets[index] = entry;
}

void *hashmap_get(hashmap_t *map, const char *key)
{
    unsigned long index = hash_string(key, map->bucket_count);
    hashmap_entry_t *entry = map->buckets[index];

    while (entry) {
        if (strcmp(entry->key, key) == 0)
            return entry->value;
        entry = entry->next;
    }
    return NULL;
}

static void handle_replacement(
    hashmap_entry_t **place,
    hashmap_entry_t *entry,
    hashmap_entry_t *prev)
{
    if (prev)
        prev->next = entry->next;
    else
        *place = entry->next;
}

static void safe_free(void *data, void (*free_func)(void *))
{
    if (free_func)
        free_func(data);
}

int hashmap_remove(hashmap_t *map, const char *key, void (*free_func)(void *))
{
    unsigned long index = hash_string(key, map->bucket_count);
    hashmap_entry_t *entry = map->buckets[index];
    hashmap_entry_t *prev = NULL;

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            handle_replacement(map->buckets + index, entry, prev);
            safe_free(entry->value, free_func);
            free(entry->key);
            free(entry);
            return 1;
        }
        prev = entry;
        entry = entry->next;
    }
    return 0;
}

void hashmap_destroy(hashmap_t *map, void (*free_func)(void *))
{
    hashmap_entry_t *entry = NULL;
    hashmap_entry_t *next = NULL;

    if (map == NULL || map->buckets == NULL)
        return;
    for (size_t i = 0; i < map->bucket_count; i++) {
        entry = map->buckets[i];
        while (entry) {
            next = entry->next;
            safe_free(entry->value, free_func);
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(map->buckets);
    free(map);
}
