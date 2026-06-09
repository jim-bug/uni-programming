/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-22
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>


void selection_sort(int*, int);
void swap(int*, int*);

int main(void){
	int n;

	do {
		printf("Inserisci la lunghezza dell'array (> 0): ");
		scanf("%d", &n);
	} while (n <= 0);

	int arr[n];

	for (int i = 0; i < n; i++){
		printf("Inserisci l'elemento alla posizione %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("Sequenza di partenza: ");
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\nSequenza ordinata: ");
	
	selection_sort(arr, n);

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int* arr, int len){
	int min_pos = 0;
	for (int i = 0; i < len-1; i++){
		for (int j = i + 1; j < len; j ++){
			if (*(arr+min_pos) > *(arr+j)) min_pos = j;
		}
		if (min_pos != i){
			swap(arr+i, arr+min_pos);
		}
	}
}
