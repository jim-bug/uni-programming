/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-04
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* dx;
    struct Node* sx;
} Node;


Node* create_node(int);
Node* insert(Node*, Node*);
int count(Node*, int);
void print_inorder(Node*);
void free_tree(Node*);


int main(int argc, char* argv[]){
    Node* root = NULL;
    int op;
    
    do {
        printf("\t1) Inserisci nodo.\n\t2) Conta nodo.\n\t3) Esci.\n");
        printf("Inserisci l'operazione: ");
        scanf("%d", &op);

        switch(op){
            case 1: {
                int value;
                printf("Inserisci il valore del nodo da aggiugere: ");
                scanf("%d", &value);

                Node* new = create_node(value);
                root = insert(root, new);

                print_inorder(root);
                printf("\n");

                break;
            }
            case 2: {
                int value;
                printf("Inserisci il valore del nodo da cercare: ");
                scanf("%d", &value);

                printf("Il nodo di valore %d compare nell'albero %d volte.\n", value, count(root, value));

                break;
            }
            case 3: free_tree(root); break;
            default: printf("Opzine non valida.\n"); break;
        }
    } while(op != 3);


    return 0;
}

Node* create_node(int value){
    Node* new = malloc(sizeof(Node));

    if (new == NULL){
        fprintf(stderr, "Impossibile allocare il nodo.\n");
        return NULL;
    }

    new->data = value;
    new->dx = NULL;
    new->sx = NULL;

    return new;
}

Node* insert(Node* root, Node* new){
    if (new == NULL) return root;
    if (root == NULL) return new;


    Node* curr = root;
    while (curr != NULL){
        // if (new->data == curr->data) return curr;
        if(new->data >= curr->data){
            if (curr->dx == NULL){
                curr->dx = new;
                return root;
            }

            curr = curr->dx;
        } else if(new->data < curr->data){
            if (curr->sx == NULL){
                curr->sx = new;
                return root;
            }
            
            curr = curr->sx;
        }
    }

    return root;
}

int count(Node* root, int value){
    int count = 0;
    while(root != NULL){
        if (root->data == value){
            count ++;
            root = root->dx;        // convenzione scelta, i duplicati sempre a destra
        } 
        else if (value > root->data){
            root = root->dx;
        } else if (value < root->data){
            root = root->sx;
        }
    }

    return count;
}

void print_inorder(Node* root){
    if (root == NULL) return;
    print_inorder(root->sx);
    printf("%d ", root->data);
    print_inorder(root->dx);
}

void free_tree(Node* root){
    if (root == NULL) return;
    free_tree(root->sx);
    free_tree(root->dx);
    free(root);
}
