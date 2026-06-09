/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-04
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_PRODUCT_NAME 100

typedef struct Promozione {
    char nome[MAX_LEN_PRODUCT_NAME + 1];
    double prezzo;
    int percentuale;
} Promozione;

typedef struct Volantino {
    struct Promozione promo;
    struct Volantino* next;
    struct Volantino* prev;
} Volantino;

Volantino* create(Promozione);
Volantino* inserisci(Volantino*, Volantino*);
Volantino* scorri(Volantino*, char);
Promozione massima_percentuale(Volantino*);
void print_promo(Promozione);
void free_volantino(Volantino*);

int main(int argc, char* argv[]){
    int op;
    Promozione promos[10] = {
        {"Pasta", 1.29, 15},
        {"Riso", 2.49, 10},
        {"Latte", 1.09, 20},
        {"Pane", 0.99, 5},
        {"Olio", 6.79, 25},
        {"Caffe", 3.49, 30},
        {"Biscotti", 2.19, 12},
        {"Formaggio", 4.59, 18},
        {"Succhi", 1.89, 8},
        {"Tonno", 3.99, 22}
    };

    Volantino* head = NULL;

    for (int i = 0; i < 10; i++){
        Volantino* nodo = create(promos[i]);
        head = inserisci(head, nodo);
    }

    do {
        printf("\t1) Sfoglia promozioni.\n\t2) Trova la prima promozione con la percentuale massima.\n\t3) Esci.\n");
        printf("Opzione scelta: ");
        scanf("%d", &op);

        switch(op){
            case 1:{
                if (head == NULL){
                    printf("Nessuna promozione disponibile.\n");
                    break;
                }

                Volantino* temp = head;
                char op;

                print_promo(head->promo);

                do {
                    printf("\t\t1) Sfoglia in avanti (>).\n\t\t2) Sfoglia indietro (<).\n\t\t3) Torna al menù principale (e).\n");
                    printf("Opzione scelta: ");
                    scanf(" %c", &op);
                    switch(op){
                        case '>':{
                            if ((temp = scorri(temp, op)) == NULL){
                                printf("\nVolantino terminato.\n");
                                break;
                            }
                            print_promo(temp->promo);

                            break;
                        }
                        case '<': {
                            if ((temp = scorri(temp, op)) == NULL){
                                printf("\nVolantino terminato.\n");
                                break;
                            }
                            print_promo(temp->promo);

                            break;
                        }
                        case 'e': break;
                        default: printf("Opzione non valida.\n");
                    }
                } while(op != 'e');

                break;
            }
            case 2: {
                print_promo(massima_percentuale(head));

                break;
            }
            case 3: free_volantino(head); break;
            default: printf("Opzione non valida.\n"); break;
        }
    } while (op != 3);

    return 0;
}

Volantino* create(Promozione promo){
    Volantino* vol = malloc(sizeof(Volantino));

    if (vol == NULL){
        fprintf(stderr, "Impossibile allocare il volantino.\n");
        return NULL;
    }

    vol->promo = promo;
    vol->next = NULL;
    vol->prev = NULL;

    return vol;
}

Volantino* inserisci(Volantino* head, Volantino* new){
    if (head == NULL) return new;
    if (new == NULL) return head;

    Volantino* curr = head;

    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = new;
    new->next = NULL;
    new->prev = curr;

    return head;
}

Volantino* scorri(Volantino* head, char verso){
    if (head == NULL) return NULL;

    if (verso == '>'){
        if (head->next == NULL) return NULL;
        return head->next;
    } else if (verso == '<') {
        if (head->prev == NULL) return NULL;
        return head->prev;
    }

    return NULL;
}

Promozione massima_percentuale(Volantino* head){
    if (head == NULL){
        Promozione vuota = {"Nessuna promozione", 0.0, 0};
        return vuota;
    }

    Promozione max_promo = head->promo;
    head = head->next;

    while(head != NULL){
        if (head->promo.percentuale > max_promo.percentuale){
            max_promo = head->promo;
        }
        head = head->next;
    }

    return max_promo;
}

void print_promo(Promozione promo){
    printf("\n\nNome promozione: %s.\n", promo.nome);
    printf("Prezzo: %.2f.\n", promo.prezzo);
    printf("Percentuale di sconto: %d.\n\n\n", promo.percentuale);
}

void free_volantino(Volantino* head){
    while(head != NULL){
        Volantino* temp = head->next;
        free(head);
        head = temp;
    }
}
