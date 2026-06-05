#include <stdio.h>
#include <stdlib.h>

char cipher(char, int);

int main(int argc, char* argv[]){
    if(argc < 4){
        printf("Use: %s <file_input> <file_output> <shift>.\n", argv[0]);
        return -1;
    }

    int shift = atoi(argv[3]);

    if (shift < 0 || shift > 25){
        printf("Lo shift deve essere compreso tra 0 e 25.\n");
        return -1;
    }

    FILE* fin;
    FILE* fout;
    char temp;

    if ((fin = fopen(argv[1], "r")) == NULL){
        printf("Impossibile aprire il file.\n");
        return -1;
    }

    if ((fout = fopen(argv[2], "w")) == NULL){
        printf("Impossibile aprire il file.\n");
        fclose(fin);
        return -1;
    }

    while(fscanf(fin, " %c", &temp) == 1){
        fprintf(fout, "%c", cipher(temp, shift));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

char cipher(char car, int shift){
    if (car >= 'a' && car <= 'z') return (car + shift - 'a') % 26 + 'a';
    if (car >= 'A' && car <= 'Z') return (car + shift - 'A') % 26 + 'A';

    return car;
}
