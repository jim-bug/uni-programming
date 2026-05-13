/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-13
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

#define MAX_LEN 100

int binary_search(int, int[], int, int);

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

	
	int index = binary_search(k, arr, 0, n-1);
	printf("\nIl numero %d %s stato trovato, posizione %d\n", k, index == -1 ? "non" : "è", index);
	return 0;
}

int binary_search(int key, int array[], int low, int high){
	int middle = (low + high) / 2;
	if (array[middle] == key) return middle;
	if (low > high) return -1;

	if (key > array[middle]) return binary_search(key, array, middle + 1, high);
	if (key < array[middle]) return binary_search(key, array, low, middle - 1);

}
