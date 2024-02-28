#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n) {
    vector vec;
    vec.data = (int *) malloc(n * sizeof(int));

    if (!vec.data) {
        fprintf(stderr, "bad alloc\n");
        exit(1);
    }

    vec.size = 0;
    vec.capacity = n;
    return vec;
}

void reserve(vector *vec, size_t newCapacity) {
    if (newCapacity == 0) {
        free(vec->data);
        vec->data = NULL;
        vec->capacity = 0;
        vec->size = 0;
    } else if (newCapacity < vec->size) {
        vec->capacity = vec->size = newCapacity;
        vec->data = (int *) realloc(vec->data, newCapacity * sizeof(int));
        if (!vec->data) {
            fprintf(stderr, "bad alloc\n");
            exit(1);
        }
    } else {
        vec->capacity = newCapacity;
        vec->data = (int *) realloc(vec->data, newCapacity * sizeof(int));
        if (!vec->data) {
            fprintf(stderr, "bad alloc\n");
            exit(1);
        }
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int*)realloc(v->data, v->size * sizeof(int));
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

#endif
