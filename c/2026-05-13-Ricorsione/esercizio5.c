/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-13
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

#define MAX_LEN 100

float max(float[], int, float, int);

int main(void) {
	float arr[MAX_LEN];
	int n;

	do {
		printf("Inserisci la lunghezza dell'array (> 0 e <= %d): ", MAX_LEN);
		scanf("%d", &n);
	} while (n <= 0 || n > MAX_LEN);
	

	for (int i = 0;i < n; i++){
		printf("Inserisci l'elemento alla posizione %d: ", i+1);
		scanf("%f", &arr[i]);
	}

	printf("\nL'elemento massimo della sequenza è: %f\n", max(arr, n, arr[0], 0));
	return 0;
}

float max(float arr[], int n, float max1, int i){
	if (i == (n - 1)) 	return max1;
	if (arr[i] > max1) 	return max(arr, n, arr[i], i+1);


	return max(arr, n, max1, i+1);
}
