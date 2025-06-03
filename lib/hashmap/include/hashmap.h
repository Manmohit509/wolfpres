/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/

#ifndef INCLUDED_HASHMAP_H
    #define INCLUDED_HASHMAP_H

    #include <stddef.h>

typedef struct hashmap_entry_s {
    char *key;
    void *value;
    struct hashmap_entry_s *next;
} hashmap_entry_t;

typedef struct hashmap_s {
    hashmap_entry_t **buckets;
    size_t bucket_count;
} hashmap_t;

hashmap_t *hashmap_create(size_t bucket_count);
void hashmap_destroy(hashmap_t *map, void (*free_func)(void *));

void hashmap_insert(hashmap_t *map, const char *key, void *value);
void *hashmap_get(hashmap_t *map, const char *key);
int hashmap_remove(hashmap_t *map, const char *key, void (*free_func)(void *));
void hashmap_foreach(
    hashmap_t *map,
    void (*func)(const char *key, void *value, void *userdata),
    void *userdata);

#endif /* INCLUDED_HASHMAP_H */
