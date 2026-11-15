/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-11-15
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
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

    if(node == NULL){
        fprintf(stderr, "Impossibile creare il Dizionario");
        return NULL;
    }

    strncpy(node->key, key, MAX_LEN_KEY);
    node->elem = elem;
    node->next = NULL;

    return node;
}

Dict* dict_create(const char* key, int elem){
    return create_pair(key, elem);
}

Dict* dict_insert(Dict* dict, const char* key, int elem){
    Dict* node = create_pair(key, elem);
    node->next = dict;

    return node;
}

Dict* dict_remove(Dict* dict, const char* key){
    while (dict != NULL && !strcmp(dict->key, key)){        // rimozione di occorrenze successive in testa
        Dict* temp = dict->next;
        free(dict);
        dict = temp;
    }

    if (dict == NULL) return NULL;                          // evito di dereferenziare NULL ai passi successivi

    Dict* prev = dict;
    Dict* curr = dict->next;

    while (curr != NULL){
        if (!strcmp(curr->key, key)){
            Dict* temp = curr->next;
            free(curr);
            prev->next = temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return dict;
}

int dict_search(const Dict* dict, const char* key, int* value){
    while(dict != NULL){
        if (!strcmp(dict->key, key)){
            *value = dict->elem;
            return 1;
        }
        dict = dict->next;
    }

    return 0;
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
