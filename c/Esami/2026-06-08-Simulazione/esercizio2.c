/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-08
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_CODE 7

typedef struct Studente {
    int matricola;
    char codice[MAX_LEN_CODE + 1];
    int voto;
} Studente;

typedef struct Nodo {
    Studente studente;
    struct Nodo* next;
} Nodo;

Nodo* create_node(Studente);
int check(Nodo*, Studente);
Nodo* insert(Nodo*, Nodo*);
int check_voto(Nodo*, int);
void exam(Nodo*);
void free_list(Nodo*);

int main(void){
    Studente studenti[3] = {
        {824363, "INF01", 28},
        {864512, "MAT01", 36},
        {824363, "INF01", 28}
    };
    Nodo* head = NULL;

    for (int i = 0; i < 3; i++){
        Nodo* new = create_node(studenti[i]);
        head = insert(head, new);
    }

    if(check_voto(head, 864512)){
        printf("Anomalia di voto presente.\n");
    }

    exam(head);

    free_list(head);

    return 0;
}

// esercizio 2
Nodo* create_node(Studente studente){
    Nodo* new = malloc(sizeof(Nodo));
    
    if (new == NULL){
        fprintf(stderr, "Impossibile allocare il nodo.\n");
        exit(EXIT_FAILURE);
    }

    new->studente = studente;
    new->next = NULL;

    return new;
}

// esercizio 2
int check(Nodo* head, Studente studente){

    while(head != NULL){
        if(head->studente.matricola == studente.matricola && !strcmp(head->studente.codice, studente.codice)){
            return 1;
        }
        head = head->next;
    }

    return 0;
}

// esercizio 2
Nodo* insert(Nodo* head, Nodo* new){

    if(check(head, new->studente)){
        free(new);
        return head;
    }

    if(head == NULL || head->studente.matricola >= new->studente.matricola){
        new->next = head;
        return new;
    }

    Nodo* curr = head;
    while(curr->next != NULL && curr->next->studente.matricola <= new->studente.matricola){
        curr = curr->next;
    }

    new->next = curr->next;
    curr->next = new;

    return head;
}

// esercizio 3
int check_voto(Nodo* head, int mat){
    while(head != NULL){
        if (head->studente.matricola == mat && (head->studente.voto < 18 || head->studente.voto > 31)){
            return 1;
        }
        head = head->next;
    }

    return 0;
}


// esercizio 4
void exam(Nodo* head){
    int count = 0;
    while(head != NULL){
        count = 0;
        int mat = head->studente.matricola;
        while(head != NULL && head->studente.matricola == mat){
            count ++;
            head = head->next;
        }
        printf("Matricola: %d: %d esami.\n", mat, count);
    }
}


// esercizio 4
void free_list(Nodo* head){
    while(head != NULL){
        Nodo* temp = head->next;
        free(head);
        head = temp;
    }
}
