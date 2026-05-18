/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-20
* 	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

int main(void) {
	char carattere;

	do {
		printf("Inserisci il carattere (lettera minuscola): ");
		scanf(" %c", &carattere);
	}
	while (!(carattere >= 'a' && carattere <= 'z'));

	// METODO ALTERNATIVO
	/*
		if (carattere == 'a' || carattere == 'e' || carattere == 'i' || carattere == 'o' || carattere == 'u'){
			printf("Il carattere: %c è una vocale\n", carattere);
		} else {
			printf("Il carattere %c è una consonante\n", carattere);
		}
	*/

	switch (carattere) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			printf("Il carattere è una vocale.\n"); 
		break;
		default:
			printf("Il carattere è una consonante.\n");
	}

	return 0;
}
