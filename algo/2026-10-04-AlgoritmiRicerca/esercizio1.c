/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-10-02
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

#define MAX 100

int linear_search(int[], int, int);

int main(){
	int n;
	int x;
	int arr[MAX];

	do {
		printf("Inserisci il numero n: ");
		scanf("%d", &n);
	} while (n < 1 || n > 100);

	printf("Inserisci il valore da cercare x: ");
	scanf("%d", &x);

	for (int i = 0; i < n; i++){
		printf("Inserisci l'elemento alla posizione %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	if (linear_search(arr, n, x) >= 0) printf("Trovato!\n");
	else printf("Non trovato\n");

	return 0;
}

int linear_search(int arr[], int n, int x){
	for (int i = 0; i < n; i++){
		if (arr[i] == x) return i;
	}

	return -1;
}
