/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-03
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <ctype.h>

#define SHIFT 13

int main(int argc, char* argv[]){
	if (argc < 2){
		printf("Use %s file.\n", argv[0]);
		return -1;
	}

	FILE* input;
	char temp;

	if ((input = fopen(argv[1], "r")) == NULL){
		printf("Impossibile aprire il file di input.\n");
		return -1;
	}

	while(fscanf(input, "%c", &temp) == 1){
		temp = toupper(temp);
		if (temp >= 'A' && temp <= 'Z') printf("%c", (temp - 'A' + SHIFT) % 26 + 'A');
		printf("%c", temp);
	}
	printf("\n");


	fclose(input);

	return 0;
}
