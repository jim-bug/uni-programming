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
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int);
Node* insert(Node*, Node*);
int search(Node*, int);
Node* find_min(Node*);
Node* find_max(Node*);
Node* delete_by_value(Node*, int);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
void level_order(Node*);
int height(Node*);
int count_nodes(Node*);
int count_leaves(Node*);
void free_tree(Node*);
void print_menu();

int main(void){
    Node* root = NULL;
    int op;

    do {
        printf("\t\t\t\t\t\tBENVENUTO NEL MENU DELLE OPERAZIONI SU ALBERO BINARIO DI RICERCA\t\t\t\t\t\t");
        print_menu();
        printf("Opzione scelta: ");
        scanf("%d", &op);

        switch(op){
            case 1: {
                int value;
                printf("Inserisci l'informazione del nodo: ");
                scanf("%d", &value);
                Node* new = create_node(value);

                root = insert(root, new);

                break;
            }
            case 2: {
                int value;
                printf("Inserisci il valore del nodo da ricercare: ");
                scanf("%d", &value);
                printf("Il nodo con informazione %d %s presente nell'albero.\n", value, search(root, value) ? "è" : "non è");

                break;
            }
            case 3: {
                int value;
                printf("Inserisci il valore del nodo da rimuovere: ");
                scanf("%d", &value);
                root = delete_by_value(root, value);

                break;
            }
            case 4: {
                Node* min = find_min(root);
                if (min != NULL) printf("Valore minimo: %d.\n", min->data);
                else printf("Albero vuoto.\n");

                break;
            }
            case 5: {
                Node* max = find_max(root);
                if (max != NULL) printf("Valore massimo: %d.\n", max->data);
                else printf("Albero vuoto.\n");

                break;
            }
            case 6: {
                printf("\nVISITA IN ORDINE (sinistra, radice, destra)\n");
                inorder(root);
                printf("\n");

                break;
            }
            case 7: {
                printf("\nVISITA IN PREORDINE (radice, sinistra, destra)\n");
                preorder(root);
                printf("\n");

                break;
            }
            case 8: {
                printf("\nVISITA IN POSTORDINE (sinistra, destra, radice)\n");
                postorder(root);
                printf("\n");

                break;
            }
            case 9: {
                printf("\nVISITA PER LIVELLI (ampiezza)\n");
                level_order(root);

                break;
            }
            case 10: {
                printf("Altezza dell'albero: %d.\n", height(root));

                break;
            }
            case 11: {
                printf("L'albero contiene %d nodi (%d foglie).\n", count_nodes(root), count_leaves(root));

                break;
            }
            case 12: {
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
                    root = insert(root, temp);
                }

                fclose(fp);
                break;

            }
            case 13: free_tree(root); root = NULL; break;
            default: printf("Opzione non valida!\n"); break;
        }
    } while (op != 13);

    return 0;
}

Node* create_node(int value){
    Node* node = malloc(sizeof (Node));
    if (node == NULL) {
        fprintf(stderr, "Impossibile allocare il nodo.\n");
        exit(EXIT_FAILURE);
    }

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, Node* new_node){
    if (new_node == NULL) return root;

    if (root == NULL) return new_node;

    if (new_node->data < root->data){
        root->left = insert(root->left, new_node);
    } else if (new_node->data > root->data){
        root->right = insert(root->right, new_node);
    } else {
        free(new_node);   // duplicato: in un BST non si inserisce
    }

    return root;
}

int search(Node* root, int value){
    while(root != NULL){
        if (value == root->data) return 1;
        root = (value < root->data) ? root->left : root->right;
    }

    return 0;
}

Node* find_min(Node* root){
    if (root == NULL) return NULL;

    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* find_max(Node* root){
    if (root == NULL) return NULL;

    while(root->right != NULL){
        root = root->right;
    }

    return root;
}

Node* delete_by_value(Node* root, int value){
    if (root == NULL) return NULL;   // valore non trovato

    if (value < root->data){
        root->left = delete_by_value(root->left, value);
    } else if (value > root->data){
        root->right = delete_by_value(root->right, value);
    } else {
        // nodo trovato: tre casi
        if (root->left == NULL){            // 0 o 1 figlio (destro)
            Node* right = root->right;
            free(root);
            return right;
        }
        if (root->right == NULL){           // 1 figlio (sinistro)
            Node* left = root->left;
            free(root);
            return left;
        }

        // 2 figli: sostituisco col successore (minimo del sottoalbero destro)
        Node* succ = find_min(root->right);
        root->data = succ->data;
        root->right = delete_by_value(root->right, succ->data);
    }

    return root;
}

void inorder(Node* root){
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root){
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void level_order(Node* root){
    if (root == NULL){
        printf("(albero vuoto)\n");
        return;
    }

    int n = count_nodes(root);
    Node** queue = malloc(n * sizeof(Node*));
    if (queue == NULL){
        fprintf(stderr, "Impossibile allocare la coda.\n");
        exit(EXIT_FAILURE);
    }

    int front = 0, rear = 0;
    queue[rear++] = root;

    while(front < rear){
        Node* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left != NULL) queue[rear++] = curr->left;
        if (curr->right != NULL) queue[rear++] = curr->right;
    }
    printf("\n");

    free(queue);
}

int height(Node* root){
    if (root == NULL) return -1;   // albero vuoto: -1, foglia: 0 (conta gli archi)

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

int count_nodes(Node* root){
    if (root == NULL) return 0;

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int count_leaves(Node* root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;

    return count_leaves(root->left) + count_leaves(root->right);
}

void free_tree(Node* root){
    if (root == NULL) return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_menu(){
    printf("\n\t1) Inserimento\n\t2) Ricerca\n\t3) Eliminazione nodo\n\t4) Valore minimo\n\t5) Valore massimo\n\t");
    printf("6) Visita in ordine (inorder)\n\t7) Visita in preordine (preorder)\n\t8) Visita in postordine (postorder)\n\t");
    printf("9) Visita per livelli (level order)\n\t10) Altezza\n\t11) Conteggio nodi e foglie\n\t12) Carica nodi da file\n\t13) Esci\n");
}
