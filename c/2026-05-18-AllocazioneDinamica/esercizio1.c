/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-18
*	Consegna: Rif. README.md
*	by jimbug // :)
*/


#include <stdio.h>
#include <stdlib.h>

int sum(int*, int);
int* create(int);

int main(void) {
	int n;
	
	do {
		printf("Inserisci il numero di elementi dell'array (> 0): ");
		scanf("%d", &n);
	} while (n <= 0);

	int *arr = create(n);

	printf("\nSomma degli elementi dell'array: %d\n\n", sum(arr, n));
	for (int i = 0; i < n; i++){
		printf("Elemento alla posizione %d: %d\n", i + 1, *(arr + 1));
	}

	free(arr);
}

int sum(int *arr, int n){
	int result = 0;
	
	for (int i = 0; i < n; i++){
		result += *(arr + i);
	}

	return result;

}

int* create(int n){
	int *arr = malloc (n * sizeof(int));
        for (int i = 0; i < n; i++){
                printf("Inserisci l'elemento alla posizione %d: ", i + 1);
                scanf("%d", arr + i);
        }

	return arr;
}
