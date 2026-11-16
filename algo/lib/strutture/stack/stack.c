/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-11-16
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdlib.h>
#include "stack.h"

struct Stack {
    int info;
    struct Stack* next;
};

static Stack* create_node(int info){
    Stack* node = malloc(sizeof(Stack));

    if (node == NULL) return NULL;

    node->info = info;
    node->next = NULL;

    return node;
}

int stack_is_empty(const Stack* stack){
    return stack == NULL;
}

StackStatus stack_push(Stack** stack, int info) {
    if (stack == NULL) return STACK_NULL_ARGUMENT;

    Stack* node = create_node(info);

    if (node == NULL) return STACK_ALLOCATION_FAILED;

    node->next = *stack;
    *stack = node;

    return STACK_OK;
}

StackStatus stack_pop(Stack** stack, int* value) {
    if (stack == NULL || value == NULL) return STACK_NULL_ARGUMENT;

    if (*stack == NULL) return STACK_EMPTY;

    Stack* old = *stack;
    *value = old->info;
    *stack = old->next;

    free(old);

    return STACK_OK;
}

StackStatus stack_top(const Stack* stack, int* value) {
    if (value == NULL) return STACK_NULL_ARGUMENT;

    if (stack == NULL) return STACK_EMPTY;

    *value = stack->info;
    return STACK_OK;
}

void stack_destroy(Stack* stack) {
    int value;

    while (stack_pop(&stack, &value) == STACK_OK) {
    }
}
