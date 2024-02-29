#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;

} vectorVoid;


#endif
