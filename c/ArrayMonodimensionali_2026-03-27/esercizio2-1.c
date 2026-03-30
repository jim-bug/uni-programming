/*
*    Autore: Ignazio Leonardo Calogero Sperandeo
*    Data: 2026-03-27
*    Consegna: Rif. README.md
*    by jimbug // :)
*/

#include <stdio.h>


int main(void) {
	int size, shift_amount;


	do {
		printf("Inserisci di quanto effettuare lo shift: ");
		scanf("%d", &shift_amount);
	} while (shift_amount < 0);
	

	do {
		printf("Inserisci la dimensione dell'array: ");
		scanf("%d", &size);

	} while (size <= 0);

	int array[size];
	
	for(int i = 0; i < size; i++) {
		printf("Inserisci l'elemento alla posizione %d dell'array: ", i);
		scanf("%d", &array[i]);
	}



	shift_amount %= size;	// ottimizzazione su quanti shift fare
	for (int shift = 0; shift < shift_amount; shift++) {		// possibile ottimizzazione: shiftare tutto in un colpo solo
		for(int i = 0; i < (size-1); i++) {
			int temporary = array[i];
			array[i] = array[i+1];
			array[i+1] = temporary;
		}
	}

	printf("Sequenza dopo lo shift di: %d volte ", shift_amount);
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
}
