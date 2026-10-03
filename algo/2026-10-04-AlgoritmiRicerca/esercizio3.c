/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-10-02
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

#define LEN 10

int binary_search(int, int[], int, int);

int main(void) {
	int arr[LEN] = {2,5,8,12,16,23,38,56,72,91};
	int x;
	printf("Inserisci il numero x da cercare: ");
	scanf("%d", &x);

	int index = binary_search(x, arr, 0, LEN-1);

	if (index >= 0) printf("Trovato!\n");
	else printf("Non trovato\n");

	return 0;
}

int binary_search(int key, int array[], int low, int high){
	if (low > high) return -1;

	int middle = (low + high) / 2;
	if (array[middle] == key) return middle;

	if (key > array[middle]) return binary_search(key, array, middle + 1, high);
	if (key < array[middle]) return binary_search(key, array, low, middle - 1);

	return -1;
}
