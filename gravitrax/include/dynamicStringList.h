#ifndef DYNAMIC_STRING_LIST_H
#define DYNAMIC_STRING_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 4

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} StringList;

static void initStringList(StringList *list) {
    list->data = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

static void addString(StringList *list, const char *str) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (char **)realloc(list->data, list->capacity * sizeof(char *));
    }
    list->data[list->size] = (char *)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(list->data[list->size], str);
    list->size++;
}

static void removeString(StringList *list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    free(list->data[index]);
    for (size_t i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

static void freeStringList(StringList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->data[i]);
    }
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

#endif // DYNAMIC_STRING_LIST_H
