/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2023-07-14
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 30
#define MAX_NUMERO 16
#define MAX_CITTA 60


typedef struct Contatto {
    char nome[MAX_NOME + 1];
    char numero[MAX_NUMERO + 1];
    char citta[MAX_CITTA + 1];
} Contatto;

typedef struct Nodo {
    Contatto contatto;
    struct Nodo* next;
} Nodo;

Nodo* create_node(Contatto);
Nodo* insert(Nodo*, Nodo*);
Nodo* find_contact(Nodo*, char[]);
void free_list(Nodo*);

int main(int argc, char* argv[]){
    Nodo* head = NULL;
    Contatto contatti[3] = {{"Ignazio", "3333333333", "Palermo"}, {"Marco", "3334533333", "Catania"}, {"Luca", "5673333333", "Agrigento"}};

    // punto 1
    for (int i = 0; i < 3; i++){
        Nodo* new = create_node(contatti[i]);
        head = insert(head, new);
    }

    // punto 2
    char nome[MAX_NOME + 1];
    printf("Inserisci il nome del nodo da ricercare: ");
    scanf(" %30[^\n]", nome);

    Nodo* find = find_contact(head, nome);
    if(find != NULL){
        printf("Nome: %s.\n", find->contatto.nome);
        printf("Numero: %s.\n", find->contatto.numero);
        printf("Citta: %s.\n\n", find->contatto.citta);
    } else {
        printf("Contatto non trovato.\n");
    }

    // punto 3
    Nodo* curr = head;
    char citta[MAX_CITTA + 1];
    printf("Inserisci il nome della citta: ");
    scanf(" %60[^\n]", citta);
    while(curr != NULL){
        if (!strcmp(curr->contatto.citta, citta)){
            printf("Nome: %s.\n", curr->contatto.nome);
            printf("Numero: %s.\n", curr->contatto.numero);
            printf("Citta: %s.\n\n", curr->contatto.citta);
        }
        curr = curr->next;
    }

    free_list(head);
    return 0;
}

Nodo* create_node(Contatto contatto){
    Nodo* new = malloc(sizeof(Nodo));

    if(new == NULL){
        printf("Impossibile allocare il nodo.\n");
        exit(1);
    }

    strcpy(new->contatto.nome, contatto.nome);
    strcpy(new->contatto.numero, contatto.numero);
    strcpy(new->contatto.citta, contatto.citta);

    new->next = NULL;

    return new;
}

Nodo* insert(Nodo* head, Nodo* new){
    if (new == NULL){
        printf("Nodo da inserire non valido.\n");
        return head;
    }

    new->next = head;

    return new;
}

Nodo* find_contact(Nodo* head, char nome[]){
    while(head != NULL){
        if (!strcmp(head->contatto.nome, nome)) return head;
        head = head->next;
    }

    return NULL;
}

void free_list(Nodo* head){
    while(head != NULL){
        Nodo* temp = head->next;
        free(head);
        head = temp;
    }
}