/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-27
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 50

int main(void){
	char str1[MAX_LEN + 1], str2[MAX_LEN + 1];

	printf("Inserisci la prima stringa: ");
	scanf("%50[^\n]", str1);

	printf("Inserisci la seconda stringa: ");
	scanf(" %50[^\n]", str2);

	if (!strcmp(str1, str2)) {
		printf("Le stringhe sono uguali!\n");
	}

	printf("Copio %s in %s.\n", str2, str1);
	strcpy(str1, str2);
	printf("Stringa risultante: %s\n", str1);

	return 0;
}
