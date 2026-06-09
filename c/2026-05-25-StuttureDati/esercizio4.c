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
    struct Node* prev;
    struct Node* next;
} Node;

Node* create_node(int);
Node* insert_from_head(Node*, Node*);
Node* insert_from_tail(Node*, Node*);
Node* insert_sorted(Node*, Node*);
Node* delete_by_value(Node*, int);
int search(Node*, int);
Node* reverse(Node*);
int count(Node*);
void print_forward(Node*);
void print_backward(Node*);
void free_list(Node*);
void print_menu();

int main(void){
    Node* head = NULL;
    int op;

    do {
        printf("\t\t\t\t\t\tBENVENUTO NEL MENU DELLE OPERAZIONI SU LISTA DOPPIAMENTE CONCATENATA\t\t\t\t\t\t");
        print_menu();
        printf("Opzione scelta: ");
        scanf("%d", &op);

        switch(op){
            case 1: {
                int value;
                printf("Inserisci l'informazione del nodo: ");
                scanf("%d", &value);
                Node* new = create_node(value);

                head = insert_from_head(head, new);

                break;
            }
            case 2: {
                int value;
                printf("Inserisci l'informazione del nodo: ");
                scanf("%d", &value);
                Node* new = create_node(value);

                head = insert_from_tail(head, new);

                break;
            }
            case 3: {
                int value;
                printf("Inserisci l'informazione del nodo: ");
                scanf("%d", &value);
                Node* new = create_node(value);

                head = insert_sorted(head, new);

                break;
            }
            case 4: {
                int value;
                printf("Inserisci il valore del nodo da rimuovere (rimuove la prima occorrenza): ");
                scanf("%d", &value);
                head = delete_by_value(head, value);

                break;
            }
            case 5: {
                int value;
                printf("Inserisci il valore del nodo da ricercare: ");
                scanf("%d", &value);
                printf("Il nodo con informazione %d %s presente nella lista.\n", value, search(head, value) ? "è" : "non è");

                break;
            }
            case 6: {
                head = reverse(head);

                break;
            }
            case 7: {
                printf("La lista contiene %d elementi.\n", count(head));

                break;
            }
            case 8: {
                printf("\nELEMENTI DELLA LISTA (testa -> coda)\n");
                print_forward(head);

                break;
            }
            case 9: {
                printf("\nELEMENTI DELLA LISTA (coda -> testa)\n");
                print_backward(head);

                break;
            }
            case 10: {
                char file_name[MAX_LEN_FILE + 1];
                FILE* fp;
                int value;
                printf("Inserisci il nome del file da cui prelevare i nodi: ");
                scanf(" %100[^\n]", file_name);

                if((fp = fopen(file_name, "r")) == NULL){
                    fprintf(stderr, "Errore nell'apertura del file.\n");
                    break;
                }

                while(fscanf(fp, "%d", &value) == 1){
                    Node* temp = create_node(value);
                    head = insert_from_tail(head, temp);
                }

                fclose(fp);
                break;

            }
            case 11: free_list(head); break;
            default: printf("Opzione non valida!\n"); break;
        }
    } while (op != 11);

    return 0;
}

Node* create_node(int value){
    Node* node = malloc(sizeof (Node));
    if (node == NULL) {
        fprintf(stderr, "Impossibile allocare il nodo.\n");
        exit(EXIT_FAILURE);
    }

    node->data = value;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

Node* insert_from_head(Node* head, Node* new_head){
    if (new_head == NULL) return head;

    new_head->prev = NULL;
    new_head->next = head;

    if (head != NULL) head->prev = new_head;

    return new_head;
}

Node* insert_from_tail(Node* head, Node* new_tail){
    if (new_tail == NULL) return head;
    if (head == NULL) return new_tail;

    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = new_tail;
    new_tail->prev = curr;
    new_tail->next = NULL;

    return head;
}

Node* insert_sorted(Node* head, Node* new_node){
    if (new_node == NULL) return head;

    if (head == NULL || new_node->data <= head->data) return insert_from_head(head, new_node);

    Node* curr = head;
    while (curr->next != NULL && curr->next->data < new_node->data){
        curr = curr->next;
    }

    new_node->next = curr->next;
    new_node->prev = curr;

    if (curr->next != NULL) curr->next->prev = new_node;
    curr->next = new_node;

    return head;
}

Node* delete_by_value(Node* head, int value){
    Node* curr = head;
    while(curr != NULL && curr->data != value){
        curr = curr->next;
    }

    if (curr == NULL) return head;   // valore non trovato

    if (curr->prev != NULL) curr->prev->next = curr->next;
    else head = curr->next;          // era la testa

    if (curr->next != NULL) curr->next->prev = curr->prev;

    free(curr);

    return head;
}

int search(Node* head, int value){
    while(head != NULL){
        if (head->data == value) return 1;
        head = head->next;
    }

    return 0;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* temp = NULL;

    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;   // avanza al nodo successivo originale
    }

    if (temp != NULL) head = temp->prev;

    return head;
}

int count(Node* head){
    int counter = 0;

    while(head != NULL){
        counter ++;
        head = head->next;
    }

    return counter;
}

void print_forward(Node* head){
    printf("NULL <- ");
    while(head != NULL){
        printf("[%d]", head->data);
        if (head->next != NULL) printf(" <-> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

void print_backward(Node* head){
    if (head == NULL){
        printf("NULL\n");
        return;
    }

    while(head->next != NULL){
        head = head->next;   // vai fino alla coda
    }

    printf("NULL <- ");
    while(head != NULL){
        printf("[%d]", head->data);
        if (head->prev != NULL) printf(" <-> ");
        head = head->prev;
    }
    printf(" -> NULL\n");
}

void free_list(Node* head){
    while(head != NULL){
        Node* temp = head->next;
        free(head);
        head = temp;
    }
}

void print_menu(){
    printf("\n\t1) Inserimento in testa\n\t2) Inserimento in coda\n\t3) Inserimento ordinato (secondo value)\n\t4) Eliminazione nodo\n\t");
    printf("5) Ricerca sequenziale\n\t6) Reverse\n\t7) Numero elementi inseriti\n\t8) Stampa (testa -> coda)\n\t9) Stampa (coda -> testa)\n\t10) Carica nodi da file (in coda)\n\t11) Esci\n");
}
