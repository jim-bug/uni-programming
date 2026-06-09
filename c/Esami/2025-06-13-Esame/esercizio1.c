/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2025-06-13
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_DEVICE 100
#define MAX_CONSUMI 100

typedef struct Consumo {
    char dispositivo[MAX_LEN_DEVICE + 1];
    int ore;
    double consumo_orario;
    double consumo_totale;
} Consumo;

int main(int argc, char* argv[]){
    if (argc < 3){
        fprintf(stderr, "Use: %s <input_file> <output_file>.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* input;
    FILE* output;
    Consumo consumi[MAX_CONSUMI];
    int last = 0;

    if ((input = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "Impossibile aprire il file.\n");
        exit(EXIT_FAILURE);
    }

    if ((output = fopen(argv[2], "w")) == NULL){
        fprintf(stderr, "Impossibile aprire il file.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    while(last < MAX_CONSUMI && fscanf(input, " %100s %d %lf", consumi[last].dispositivo, &consumi[last].ore, &consumi[last].consumo_orario) == 3){
        consumi[last].consumo_totale = (double)consumi[last].ore * consumi[last].consumo_orario;

        if (consumi[last].consumo_totale > 100.0){
            fprintf(output, "%s\n", consumi[last].dispositivo);
        }

        last ++;
    }
    fclose(input);

    if (last == 0){
        printf("Nessuna informazione letta dal file.\n");
        fclose(output);
        exit(EXIT_SUCCESS);
    }

    Consumo max = consumi[0];
    Consumo min = consumi[0];

    for (int i = 0; i < last; i++){
        if (consumi[i].consumo_totale > max.consumo_totale){
            max = consumi[i];
        }

        if (consumi[i].consumo_totale < min.consumo_totale){
            min = consumi[i];
        }
    }

    fprintf(output, "Nome del dispositivo con il consumo minimo: %s.\n", min.dispositivo);
    fprintf(output, "Nome del dispositivo con il consumo massimo: %s.\n", max.dispositivo);

    fclose(output);

    return 0;
}