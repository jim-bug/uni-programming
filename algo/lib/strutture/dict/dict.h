/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-11-15
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#ifndef DICT_H
#define DICT_H

#define MAX_LEN_KEY 20

typedef struct Dict Dict;
typedef enum {
    DICT_OK,
    DICT_NULL_ARGUMENT,
    DICT_KEY_NOT_FOUND,
    DICT_KEY_TOO_LONG,
    DICT_ALLOCATION_FAILED
} DictStatus;

DictStatus dict_insert(Dict**, const char*, int);
DictStatus dict_remove(Dict**, const char*);
DictStatus dict_search(const Dict*, const char*, int*);
void dict_destroy(Dict*);

#endif