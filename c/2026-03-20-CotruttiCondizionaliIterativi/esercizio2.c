/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-20
* 	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

int main(void) {
	int year;
	
	do {
		printf("Inserisci l'anno (a partire da 1): ");
		scanf("%d", &year);
	} while (year < 0);

	if (year % 4 == 0 && year % 100 == 0 || year % 400 == 0){
		printf("L'anno %d è bisestile.\n", year);
	} else {
		printf("L'anno %d non è bisestile.\n", year);
	}

	return 0;
}
