/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-04
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* create_node(int);
Node* insert(Node*, Node*);
int count(Node*, int);
Node* delete(Node*, int);
Node* modify(Node*);
void print(Node*);
void free_list(Node*);

int main(int argc, char* argv[]){
    Node* head = NULL;
    int op;

    do{
        printf("\t1) Inserisci un nuovo nodo.\n\t2) Conta quante volte un numero appare in lista.\n\t3) Cancella tutte le occorrenze dei nodi che contengono uno specifico valore.\n\t4) Modifica lista riassegnando ad ogni numero il suo quadrato.\n\t5) Esci.\n");
        printf("Inserisci l'operazione da effettuare: ");
        scanf("%d", &op);

        switch(op){
            case 1: {
                int value;
                printf("Inserisci il valore del nodo da aggiungere: ");
                scanf("%d", &value);

                Node* new = create_node(value);
                head = insert(head, new);

                print(head);

                break;
            }
            case 2: {
                int value;
                printf("Inserisci il valore del nodo da cercare: ");
                scanf("%d", &value);

                printf("Il valore %d compare nella lista %d volte.\n", value, count(head, value));

                break;
            }
            case 3: {
                int value;
                printf("Inserisci il valore del nodo da eliminare: ");
                scanf("%d", &value);

                head = delete(head, value);

                print(head);

                break;
            }
            case 4: modify(head); print(head); break;
            case 5: free_list(head); break;

            default:
                printf("Opzione non valida.\n");
                break;
        }
    }  while(op != 5);

    return 0;
}

Node* create_node(int value){
    Node* node = malloc(sizeof(Node));

    if(node == NULL){
        fprintf(stderr, "Impossibile allocare il nodo.\n");
        return NULL;
    }

    node->data = value;
    node->next = NULL;

    return node;
}

Node* insert(Node* head, Node* new){
    if(new == NULL) return head;

    if(head == NULL || new->data <= head->data){
        new->next = head;
        return new;
    }

    Node* curr = head;
    while(curr->next != NULL && curr->next->data <= new->data){
        curr = curr->next;
    }

    new->next = curr->next;
    curr->next = new;

    return head;
}

int count(Node* head, int value){
    int count = 0;
    while(head != NULL){
        if (head->data == value) count ++;

        head = head->next;
    }

    return count;
}

Node* delete(Node* head, int value){

    while (head != NULL && head->data == value) {
        Node* temp = head->next;
        free(head);
        head = temp;
    }

    if (head == NULL) return NULL;

    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL) {
        if (curr->data == value) {
            Node* temp = curr->next;
            free(curr);
            prev->next = temp;
            curr = temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

Node* modify(Node* head){
    Node* curr = head;
    while(curr != NULL){
        curr->data *= curr->data;
        curr = curr->next;
    }

    return head;
}

void print(Node* head){
    while(head != NULL){
        printf("[%d: *] -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(Node* head){
    while(head != NULL){
        Node* temp = head->next;
        free(head);
        head = temp;
    }
}
