/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2025-06-13
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOLO 10
#define MAX_POSTO 4

typedef struct CheckIn {
    int id;
    char n_volo[MAX_VOLO + 1];
    char posto[MAX_POSTO + 1];
} CheckIn;

typedef struct Nodo {
    CheckIn check_in;
    struct Nodo* next;
} Nodo;

Nodo* create_node(CheckIn);
int check(Nodo*, CheckIn);
Nodo* insert(Nodo*, Nodo*);
int check_overbooking(Nodo*, char[]);
void free_list(Nodo*);

int main(void){
    // esercizio 4: punto 1
    CheckIn check_in[3] = {
        {0, "AZ123", "12A"},
        {13, "ZA213", "23C"},
        {1, "AZ123", "12A"}
    };
    Nodo* head = NULL;

    for (int i = 0; i < 3; i++){
        Nodo* new = create_node(check_in[i]);
        head = insert(head, new);
    }

    // esercizio 4: punto 2
    if (check_overbooking(head, "AZ123")){
        printf("Conflitto di overbooking trovato.\n");
    } else {
        printf("Nessun conflitto di overbooking.\n");
    }

    // esercizio 4: punto 3
    Nodo* curr = head;
    while(curr != NULL){
        int apparso = 0;
        Nodo* temp = head;

        while(temp != curr){
            if (strcmp(temp->check_in.n_volo, curr->check_in.n_volo) == 0){
                apparso = 1;
                break;
            }
            temp = temp->next;
        }

        if (apparso){
            curr = curr->next;
            continue;
        }

        int count = 0;

        Nodo* counter = curr;
        while(counter != NULL){
            if (strcmp(counter->check_in.n_volo, curr->check_in.n_volo) == 0) count ++;

            counter = counter->next;
        }

        printf("Volo: %s, passeggeri: %d.\n", curr->check_in.n_volo, count);

        curr = curr->next;
    }


    free_list(head);
    return 0;
}

// esercizio 2
Nodo* create_node(CheckIn check_in){
    Nodo* new = malloc(sizeof(Nodo));

    if (new == NULL){
        fprintf(stderr, "Impossibile allocare il nodo.\n");
        exit(EXIT_FAILURE);
    }

    new->check_in = check_in;
    new->next = NULL;

    return new;
}

// esercizio 2
int check(Nodo* head, CheckIn check_in){
    while(head != NULL){
        if (head->check_in.id == check_in.id && strcmp(head->check_in.n_volo, check_in.n_volo) == 0){
            return 1;   // check_in già esistente
        }
        head = head->next;
    }

    return 0;
}

// esercizio 2
Nodo* insert(Nodo* head, Nodo* new){
    if(check(head, new->check_in)){
        free(new);
        return head;
    }

    if (head == NULL || head->check_in.id >= new->check_in.id){
        new->next = head;
        return new;
    }

    Nodo* curr = head;
    while(curr->next != NULL && curr->next->check_in.id <= new->check_in.id){
        curr = curr->next;
    }

    new->next = curr->next;
    curr->next = new;

    return head;
}

// esercizio 3
int check_overbooking(Nodo* head, char volo[]){
    while(head != NULL){
        if (strcmp(head->check_in.n_volo, volo) != 0){
            head = head->next;
            continue;
        }
        Nodo* temp = head->next;
        while(temp != NULL){
            if (strcmp(temp->check_in.n_volo, volo) == 0 &&
                strcmp(temp->check_in.posto, head->check_in.posto) == 0){
                return 1;
            }
            temp = temp->next;
        }

        head = head->next;
    }

    return 0;
}

// esercizio 4
void free_list(Nodo* head){
    while(head != NULL){
        Nodo* temp = head->next;
        free(head);
        head = temp;
    }
}