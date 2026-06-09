/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-08
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_CODE 10
#define MAX_DELIVERY 100

typedef struct Spedizione {
    char code[MAX_LEN_CODE + 1];
    int distance;
    double weight;
    double price;
} Spedizione;


int main(int argc, char* argv[]){
    if (argc < 3) {
        fprintf(stderr, "Use: %s <input_file> <output_file>.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* input;
    FILE* output;
    Spedizione spedizioni[MAX_DELIVERY];
    char code[MAX_LEN_CODE + 1];
    int distance;
    double weight;
    int last_delivery = 0;

    if ((input = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "Impossibile aprire il file.\n");
        exit(EXIT_FAILURE);
    }

    if ((output = fopen(argv[2], "w")) == NULL){
        fprintf(stderr, "Impossibile aprire il file.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    while(last_delivery < MAX_DELIVERY && fscanf(input, " %10s %d %lf", code, &distance, &weight) == 3){
        double temp_price = (double)distance * weight;
        strcpy(spedizioni[last_delivery].code, code);
        spedizioni[last_delivery].distance = distance;
        spedizioni[last_delivery].weight = weight;
        spedizioni[last_delivery].price = temp_price;

        if (temp_price > 50.0){
            fprintf(output, "%s\n", spedizioni[last_delivery].code);
        }

        last_delivery ++;
    }
    fclose(input);

    if (last_delivery == 0){
        fprintf(stderr, "Spedizioni non trovate nel file.\n");
        fclose(output);
        exit(EXIT_FAILURE);
    }

    Spedizione max = spedizioni[0];
    Spedizione min = spedizioni[0];
    for (int i = 1; i < last_delivery; i++){
        if (spedizioni[i].price > max.price){
            max = spedizioni[i];
        }
        if (spedizioni[i].price < min.price){
            min = spedizioni[i];
        }
    }

    fprintf(output, "Spedizione con costo di spedizione più alto: %s\n", max.code);
    fprintf(output, "Spedizione con costo di spedizione più basso: %s\n", min.code);

    fclose(output);

    return 0;
}
