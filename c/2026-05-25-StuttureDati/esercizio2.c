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

Node* create_node(int);
Node* push(Node*, Node*);
Node* pop(Node*, int*);
int is_empty(Node*);
int peek(Node*, int*);
void print(Node*);
void free_stack(Node*);
void print_menu();

int main(void){
    Node* head = NULL;
    int op;

    do {
        printf("\t\t\t\t\t\tBENVENUTO NEL MENU DELLE OPERAZIONI SU LISTA CONCATENATA\t\t\t\t\t\t");
        print_menu();
        printf("Opzione scelta: ");
        scanf("%d", &op);

        switch(op){
            case 1: {
                int value;
                printf("Inserisci il valore del nodo da inserire: ");
                scanf("%d", &value);
                Node* new = create_node(value);
                head = push(head, new);

                break;
            }
            case 2: {
                if (is_empty(head)){
                    printf("Pila vuota.\n");
                    break;
                }

                int value;
                head = pop(head, &value);

                printf("Il valore eliminato è: %d.\n", value);

                break;
            }
            case 3: {
                int value;
                if (peek(head, &value)){
                    printf("Il valore del primo nodo è: %d.\n", value);
                } else {
                    printf("Pila vuota.\n");
                }

                break;
            }
            case 4:{
                print(head);

                break;
            }
            case 5: {
                char file_name[MAX_LEN_FILE + 1];
                FILE* fp;
                int value;
                printf("Inserisci il nome del file: ");
                scanf(" %100[^\n]", file_name);

                if((fp = fopen(file_name, "r")) == NULL){
                    fprintf(stderr, "Impossibile aprire il file.\n");
                    break;
                }

                while(fscanf(fp, "%d", &value) == 1){
                    Node* temp = create_node(value);
                    head = push(head, temp);
                }

                fclose(fp);

                break;

            }
            case 6: free_stack(head); break;
            default: printf("Opzione non valida.\n"); break;
        }
    } while(op != 6);


    return 0;
}

Node* create_node(int value){
    Node* top = malloc(sizeof(Node));
    if (top == NULL){
        fprintf(stderr, "Impossibile allocare il nodo.\n");
        return NULL;
    }

    top->data = value;
    top->next = NULL;

    return top;
}

Node* push(Node* top, Node* new){
    if (new == NULL) return top;

    new->next = top;

    return new;
}

Node* pop(Node* top, int* value){
    if(top == NULL) return NULL;

    Node* temp = top->next;
    *value = top->data;
    free(top);

    return temp;
}

int is_empty(Node* top){
    return top == NULL;
}

int peek(Node* top, int* top_value){
    if (is_empty(top)) return 0;

    *top_value = top->data;
    return 1;
}

void print(Node* top){
    while(top != NULL){
        printf("%d\n", top->data);
        top = top->next;
    }
    printf("\n");
}

void free_stack(Node* top){
    while(top != NULL){
        Node* temp = top->next;
        free(top);
        top = temp;
    }
}

void print_menu(){
    printf("\n\t1) Push\n\t2) Pop\n\t3) Peek\n\t4) Stampa\n\t5) Carica nodi da file\n\t6) Esci\n");
}
