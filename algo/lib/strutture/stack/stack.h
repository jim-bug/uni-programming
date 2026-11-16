/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-11-16
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;
typedef enum {
    STACK_OK,
    STACK_NULL_ARGUMENT,
    STACK_EMPTY,
    STACK_ALLOCATION_FAILED
} StackStatus;

int stack_is_empty(const Stack*);
StackStatus stack_push(Stack**, int);
StackStatus stack_pop(Stack**, int*);
StackStatus stack_top(const Stack*, int*);
void stack_destroy(Stack*);

#endif