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

Dict* dict_create(const char* key, int elem);
Dict* dict_insert(Dict* dict,  const char* key, int elem);
Dict* dict_remove(Dict* dict, const char* key);
int dict_search(const Dict* dict, const char* key, int* value);
void dict_destroy(Dict* dict);


#endif