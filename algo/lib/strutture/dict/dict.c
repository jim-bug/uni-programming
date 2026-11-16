/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-11-15
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdlib.h>
#include <string.h>
#include "dict.h"

struct Dict {
    char key[MAX_LEN_KEY];
    int elem;
    struct Dict* next;
};

static Dict* create_pair(const char* key, int elem){
    Dict* node = malloc(sizeof(Dict));

    if (node == NULL) return NULL;

    strcpy(node->key, key);
    node->elem = elem;
    node->next = NULL;

    return node;
}

DictStatus dict_insert(Dict** dict, const char* key, int elem) {
    if (dict == NULL || key == NULL) return DICT_NULL_ARGUMENT;

    if (strlen(key) >= MAX_LEN_KEY) return DICT_KEY_TOO_LONG;

    Dict* node = create_pair(key, elem);

    if (node == NULL) return DICT_ALLOCATION_FAILED;

    node->next = *dict;
    *dict = node;

    return DICT_OK;
}

DictStatus dict_remove(Dict** dict, const char* key) {
    if (dict == NULL || key == NULL) return DICT_NULL_ARGUMENT;

    int removed = 0;

    while (*dict != NULL && strcmp((*dict)->key, key) == 0) {           // rimozione di occorrenze successive in testa
        Dict* temp = (*dict)->next;
        free(*dict);
        *dict = temp;
        removed = 1;
    }

    if (*dict == NULL) return removed ? DICT_OK : DICT_KEY_NOT_FOUND;   // evito di dereferenziare NULL (in caso) ai passi successivi

    Dict* prev = *dict;
    Dict* curr = (*dict)->next;

    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
            removed = 1;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return removed ? DICT_OK : DICT_KEY_NOT_FOUND;
}

DictStatus dict_search(const Dict* dict, const char* key, int* value) {
    if (key == NULL || value == NULL) return DICT_NULL_ARGUMENT;

    while (dict != NULL) {
        if (strcmp(dict->key, key) == 0) {
            *value = dict->elem;
            return DICT_OK;
        }
        dict = dict->next;
    }

    return DICT_KEY_NOT_FOUND;
}

static void free_dict(Dict* dict){
    while(dict != NULL){
        Dict* temp = dict->next;
        free(dict);
        dict = temp;
    }
}

void dict_destroy(Dict* dict){
    free_dict(dict);
}
