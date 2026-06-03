/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-03
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

#define MAX_LEN_FILE 30

int main(void){
	FILE* fp;
	char file_name[MAX_LEN_FILE + 1];
	int count = 0;
	char temp;

	printf("Inserisci il nome del file: ");
	scanf(" %30[^\n]", file_name);

	if ((fp = fopen(file_name, "r")) == NULL){
		printf("Errore nell'apertura del file.\n");
		return -1;
	}


	while (fscanf(fp, "%c", &temp) == 1){
		if (temp == '\n') count ++;
	}

	printf("Il numero di andate a capo presente nel file di nome %s è %d.\n", file_name, count);
	
	
	fclose(fp);
	return 0;
}
