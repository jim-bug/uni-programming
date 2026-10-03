/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-10-02
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

#define LEN 10

int binary_search(int[], int, int);

int main(){
	int x;
	int arr[LEN] = {2,5,8,12,16,23,38,56,72,91};
	
	printf("Inserisci il valore da cercare x: ");
	scanf("%d", &x);

	if (binary_search(arr, LEN, x) >= 0) printf("Trovato!\n");
	else printf("Non trovato\n");

	return 0;
}

int binary_search(int arr[], int n, int x){
	int low = 0;
	int high = n - 1;
	int step = 1;

	while (low <= high){
		int mid = (low + high) / 2;

		printf("Passo: %d - low: %d - high: %d - mid: %d\n", step, low, high, mid);
		if (x == arr[mid]) return mid;

		if (x > arr[mid]) low = mid + 1;
		else high = mid - 1;

		step++;
	}

	return -1;
}
