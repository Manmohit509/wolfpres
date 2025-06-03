/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my
*/

#ifndef INCLUDED_VECTOR_H
    #define INCLUDED_VECTOR_H

    #define SUCCESS 0
    #define INFERIOR_SIZE_ERR 1
    #define ALLOC_FAIL_ERR 2
    #define VECTOR_EMPTY_ERR 3
    #define OUT_OF_BAND 4
    #define V_MIN(a, b) ((a) > (b) ? (b) : (a))

    #include <stdbool.h>
    #include <stddef.h>

typedef struct _vector_t {
    size_t capacity;
    size_t used_capacity;
    size_t block_size;
} _vector_t;

void clear_n_bytes(void *ptr, size_t size);
void copy_n_bytes(void *dest, void *src, size_t size);

void *vector_create(size_t init_size, size_t block_size);
void vector_destroy(void *vec, void (*free_method)(void *data_ptr));

void vector_push_back(void **vec, void *value_ptr);
int vector_pop_back(void *vec);

//todo Implement
void vector_insert(void **vec, size_t index, void *value_ptr);
void vector_erase(void *vec, size_t index);

int vector_set(void **vec, size_t index, void *value);
size_t vector_size(void const *vec);
size_t vector_capacity(void *vec);

int vector_resize(void **vec, size_t new_size);
//todo Implement
void vector_reserve(void **vec, size_t new_capacity);

void vector_clear(void *vec);
bool vector_is_empty(void *vec);

//todo Implement
void vector_print(void *vec, void (*printer)(void *data_ptr));

void simple_free(void *ptr);

#endif /* INCLUDED_VECTOR_H */
