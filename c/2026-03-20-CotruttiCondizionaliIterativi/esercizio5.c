/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-20
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int main(void) {
	int x;
	long long fattoriale = 1;

	do {
		printf("Inserisci il valore di x: ");
		scanf("%d", &x);
	} while (x < 0);

	
	for(int i = 1; i <= x; i++) {
		fattoriale *= i;
	}
	
	printf("Il fattoriale di %d è %lld.\n", x, fattoriale);

	return 0;
}
