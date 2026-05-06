/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-20
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int main(void) {
	int n, temp;
	int f0 = 1, f1 = 1;

	do {
		printf("Inserisci il valore di n (strettamente maggiore di 0): ");
		scanf("%d", &n);
	} while (n <= 0);

	printf("Serie di fibonacci di %d numeri: \n", n);
	
	for(int i = 0; i < n; i++) {
		printf("%d ", f0);
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
			
	}
	printf("\n");
	
	return 0;
}
