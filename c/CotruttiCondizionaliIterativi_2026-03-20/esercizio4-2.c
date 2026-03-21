/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-20
* 	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

int main(void) {
	char carattere;

	printf("Inserisci il carattere (lettera minuscola): ");
	scanf(" %c", &carattere);
	
	if (carattere >= 'A' && carattere <= 'Z'){
		carattere += 32;
	} else {
		while (!(carattere >= 'a' && carattere <= 'z')) {
			printf("Inserisci il carattere (lettera minuscola): ");
			scanf(" %c", &carattere);
		}
	}

	switch (carattere) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			printf("Il carattere è una vocale.\n"); 
		break;
		default:
			printf("Il carattere è una consonante.\n");
	}


	return 0;
}
