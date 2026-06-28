/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-10
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITOLO 50
#define MAX_CODE 10
#define MAX_TYPE 20

typedef struct Opera {
    char titolo[MAX_TITOLO];
    char codice[MAX_CODE];
    char corrente[MAX_TYPE];
} Opera;

typedef struct Nodo {
    Opera opera;
    struct Nodo* next;
} Nodo;

Nodo* create_node(Opera);
Nodo* check(Nodo*, char[]);
Nodo* insert(Nodo*, Nodo*);
int check_overbooking(Nodo*, char[]);
void free_list(Nodo*);

int main(void){
    // esercizio 4: punto 1
    Opera opere[3] = {
        {"Magnifico", "12A55", "Medioevo"},
        {"Luce nel buio", "12B13", "Barocco"},
        {"Persico", "12A55", "Medioevo"}
    };
    Nodo* head = NULL;

    for (int i = 0; i < 3; i++){
        if (check(head, opere[i].codice) == NULL){
            Nodo* new = create_node(opere[i]);
            head = insert(head, new);
        }
        else {
            printf("Opera: %s già presente nell'inventario.\n", opere[i].codice);
        }
    }

    // esercizio 4: punto 2
    Nodo* esito;
    if ((esito = check(head, "12B13")) != NULL){
        printf("Titolo: %s\nCodice: %s\nCorrente: %s\n", esito->opera.titolo, esito->opera.codice, esito->opera.corrente);
    } else {
        printf("Opera non presente.\n");
    }

    // esercizio 4: punto 3
    char corrente[MAX_TYPE];
    printf("Inserisci la corrente artistica: ");
    scanf(" %20[^\n]", corrente);

    Nodo* curr = head;
    
    while (curr != NULL){
        if(!strcmp(curr->opera.corrente, corrente)){
            printf("Titolo: %s\nCodice: %s\nCorrente: %s\n", curr->opera.titolo, curr->opera.codice, curr->opera.corrente);
        }
        curr = curr->next;
    }


    free_list(head);
    return 0;
}

// esercizio 2
Nodo* create_node(Opera opera){
    Nodo* new = malloc(sizeof(Nodo));

    if (new == NULL){
        fprintf(stderr, "Impossibile allocare il nodo.\n");
        exit(EXIT_FAILURE);
    }

    new->opera = opera;
    new->next = NULL;

    return new;
}

// esercizio 2
Nodo* insert(Nodo* head, Nodo* new){
    if (new == NULL) return head;

    new->next = head;
    head = new;

    return head;
}

// esercizio 3
Nodo* check(Nodo* head, char codice[]){
    while(head != NULL){
        if (!strcmp(head->opera.codice, codice)){
            return head;       // opera già esistente
        }
        head = head->next;
    }

    return NULL;
}

// esercizio 4
void free_list(Nodo* head){
    while(head != NULL){
        Nodo* temp = head->next;
        free(head);
        head = temp;
    }
}
