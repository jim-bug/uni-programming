/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-25
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_FILE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;


Node* create_node(int);
void enqueue(Queue*, Node*);
int dequeue(Queue*, int*);
int front(Queue*, int*);
int is_empty(Queue*);
void print(Queue*);
void free_queue(Queue*);
void print_menu();


int main(void){
    Queue* coda = {NULL, NULL};
    int op;

    do {
        printf("\t\t\t\t\t\tBENVENUTO NEL MENU DELLE OPERAZIONI SU LISTA CONCATENATA\t\t\t\t\t\t");
        print_menu();
        printf("Opzione scelta: ");
        scanf("%d", &op);

        switch(op){
            case 1:{
                int value;
                printf("Inserisci il valore del nodo da aggiungere: ");
                scanf("%d", &value);
                Node* new = create_node(value);

                enqueue(coda, new);

                break;
            }
            case 2: {
                int value;

                if (dequeue(coda, &value)){
                    printf("Il valore del nodo appena rimosso è: %d.\n", value);
                } else {
                    printf("Coda vuota.\n");
                }

                break;
            }
            case 3: {
                int value;
                if (front(coda, &value)){
                    printf("Valore del primo nodo: %d.\n", value);
                } else {
                    printf("Coda vuota.\n");
                }

                break;
            }
            case 4: {
                print(coda);

                break;
            }
            case 5: {
                char file_name[MAX_LEN_FILE + 1];
                FILE* fp;
                int value;
                printf("Inserisci il nome del file: ");
                scanf(" %100[^\n]", file_name);

                if((fp = fopen(file_name, "r")) == NULL){
                    printf("Impossibile aprire il file.\n");
                    break;
                }

                while(fscanf(fp, "%d", &value) == 1){
                    Node* temp = create_node(value);
                    enqueue(coda, temp);
                }

                fclose(fp);

                break;            
            }
            case 6: free_queue(coda); break;
            default: printf("Opzione non valida.\n"); break;
        }
    } while(op != 5);

    return 0;
}

Node* create_node(int value){
    Node* head = malloc(sizeof(Node));

    if(head == NULL){
        printf("Impossibile allocare il nodo.\n");
        return NULL;
    }

    head->data = value;
    head->next = NULL;

    return head;
}

void enqueue(Queue* coda, Node* new){
    if (new == NULL) return;

    if (coda->tail == NULL){
        coda->head = new;
        coda->tail = new;
    } else{
        coda->tail->next = new;
        coda->tail = new;
    }
}

int dequeue(Queue* coda, int* value){
    if (coda->head == NULL) return 0;

    Node* temp = coda->head;
    *value = temp->data;
    coda->head = temp->next;

    if (coda->head == NULL) coda->tail = NULL;

    free(temp);

    return 1;
}

int is_empty(Queue* coda){
    return coda->head == NULL;
}

int front(Queue* coda, int* value){
    if (is_empty(coda)) return 0;

    *value = coda->head->data;
    
    return 1;
}

void print(Queue* coda){
    Node* curr = coda->head;
    printf("FRONT -> ");
    while(curr != NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("BACK\n");
}

void free_queue(Queue* coda){
    Node* curr = coda->head;

    while(curr != NULL){
        Node* temp = curr->next;
        free(curr);
        curr = temp;
    }

    // evito il dangling pointer
    coda->head = NULL;
    coda->tail = NULL;
}

void print_menu(){
    printf("\n\t1) Enqueue\n\t2) Dequeue\n\t3) Front\n\t4) Stampa\n\t5) Carica nodi da file\n\t6) Esci\n");
}
