/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-13
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int linear_search(int[], int, int, int);

int main(void) {
	int arr[MAX_LEN];
	int n, k;

	do {
		printf("Inserisci la lunghezza dell'array (> 0 e <= %d): ", MAX_LEN);
		scanf("%d", &n);
	} while (n <= 0 || n > MAX_LEN);
	

	printf("Inserisci l'elemento da cercare: ");
	scanf("%d", &k);

	for (int i = 0;i < n; i++){
		printf("Inserisci l'elemento alla posizione %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	int index = linear_search(arr, n, k, 0);
	printf("\nL'elemento %d %s stato trovato, posizione: %d\n", k, index == -1 ? "non" : "è", index);

	return 0;
}

int linear_search(int arr[], int n, int k, int i){
	if (arr[i] == k) 	return i;
	if ((n - 1) == i)	return -1;

	return linear_search(arr, n, k, i+1);
}

