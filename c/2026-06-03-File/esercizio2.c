/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-03
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <ctype.h>


#define ALPHABET_LEN 26
#define MAX_LEN_FILE 100

int main(int argc, char* argv[]){
	if (argc < 2){
		printf("Use %s file.\n", argv[0]);
		return -1;
	}

	FILE* input;
	FILE* output;
	int counter[26] = {0};
	char str[MAX_LEN_FILE + 1];
	char occorrence = 'a';

	if ((input = fopen(argv[1], "r")) == NULL){
		printf("Impossibile aprire il file di input.\n");
		return -1;
	}

	if ((output = fopen("frequenza_lettere.txt", "w")) == NULL){
		printf("Impossibile aprire il file di output.\n");
		return -1;
	}

	while(fscanf(input, "%100s", str) == 1){ 
		for (int i = 0; i < strlen(str); i++){
			counter[tolower(str[i]) - 'a'] ++;
		}
	}
	
	for (int i = 0; i < ALPHABET_LEN; i++){
		fprintf(output, "Occorrenze di %c: %d\n", i + 'a', counter[i]);
	}

	fclose(input);
	fclose(output);

	return 0;
}
