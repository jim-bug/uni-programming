/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-13
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

int odd_sum(int, int);

int main(void) {
	int n, k;


	do {
		printf("Insersci quanti numeri pari vuoi sommare: ");
        	scanf("%d", &n);
	} while (n <= 0);

	printf("Inserisci il numero soglia: ");
	scanf("%d", &k);


	printf("Somma dei primi %d numeri maggiori si %d: %d\n", n, k, odd_sum(n, k + 1));
	return 0;
}

int odd_sum(int n, int k){
	if (n == 0) return 0;

	if (k % 2 == 0) return odd_sum(n - 1, k + 1) + k;
	return odd_sum(n, k + 1);
}
