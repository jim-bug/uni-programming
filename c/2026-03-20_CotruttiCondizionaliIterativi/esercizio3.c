/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-20
* 	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

int main(void) {
	int n1, n2, n3;
	printf("Inserisci il valore di n1: ");
	scanf("%d", &n1);
	printf("Inserisci il valore di n2: ");
	scanf("%d", &n2);
	printf("Inserisci il valore di n3: ");
	scanf("%d", &n3);
	
	printf("Sequenza iniziale: %d %d %d\n", n1, n2, n3);
	
	if (n1 > n2) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
	} 
	if (n2 > n3) {
		int temp = n2;
		n2 = n3;
		n3 = temp;
	}
	if (n1 > n2) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}
	
	printf("Sequenza ordinata: %d %d %d\n", n1, n2, n3);
	return 0;
}
