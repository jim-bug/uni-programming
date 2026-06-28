/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-10
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODOTTI 100
#define MAX_NOME 50

typedef struct Prodotto {
    char nome[MAX_NOME];
    int vendite;
} Prodotto;

int main(int argc, char* argv[]){
    if (argc < 4){
        fprintf(stderr, "Use: %s <input_file> <output_file> <S>.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int S = atoi(argv[3]);

    if (S < 0) {
        fprintf(stderr, "Soglia vendita non valida (>= 0).\n");
        exit(EXIT_FAILURE);
    }

    FILE* input;
    FILE* output;
    Prodotto prodotti[MAX_PRODOTTI];
    int last = 0;
    int counter = 0;

    if ((input = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "Impossibile aprire il file.\n");
        exit(EXIT_FAILURE);
    }

    if ((output = fopen(argv[2], "w")) == NULL){
        fprintf(stderr, "Impossibile aprire il file.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    while(last < MAX_PRODOTTI && fscanf(input, " %100s %d", prodotti[last].nome, &prodotti[last].vendite) == 2){
        if (prodotti[last].vendite > S) counter ++;
        last ++;
    }
    fclose(input);

    if (last == 0){
        printf("Nessuna informazione letta dal file.\n");
        fclose(output);
        exit(EXIT_SUCCESS);
    }


    fprintf(output, "Numero di prodotti che hanno superato la soglia: %d.\n", counter);

    for (int i = 0; i < last; i++){
        if (prodotti[last].vendite > S) fprintf(output, "Nome prodotto: %s.\n", prodotti[last].nome);
    }

    fclose(output);

    return 0;
}
