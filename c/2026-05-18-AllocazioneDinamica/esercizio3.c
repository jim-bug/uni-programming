/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-18
*	Consegna: Rif. README.md
*	by jimbug // :)
*/


#include <stdio.h>
#include <stdlib.h>

int* unisci_array(int[], int[], int, int);

int main(void) {
	int n1, n2;

	do {
		printf("Inserisci la lunghezza del primo array (> 0): ");
		scanf("%d", &n1);
	} while (n1 <= 0);

	do {
		printf("Inserisci la lunghezza del secondo array (> 0): ");
		scanf("%d", &n2);
	} while (n2 <= 0);


	int v1[n1], v2[n2];

	for (int i = 0; i < n1; i++){
		printf("Inserisci l'elemento del primo array alla posizione %d: ", i + 1);
		scanf("%d", &v1[i]);
	}

	printf("\n");

        for (int i = 0; i < n2; i++){ 
                printf("Inserisci l'elemento del secondo array alla posizione %d: ", i + 1);
                scanf("%d", &v2[i]);
        }

	int *arr = unisci_array(v1, v2, n1, n2);

	if (arr == NULL){
		fprintf(stderr, "Impossibile allocare la memoria\n");
		return -1;
	}

	printf("\nArray risultante: ");
	for (int i = 0; i < n1 + n2; i++){
		printf("%d ", *(arr + i));
	}

	printf("\n");

	free(arr);

	return 0;
}

int* unisci_array(int v1[], int v2[], int n1, int n2){
	int *new_arr = malloc((n1 + n2) * sizeof(int));
	int new_len = n1 + n2;
	int i = 0, j = 0;

	for (int k = 0; k < new_len; k++){
		int temp;
		if (i > (n1 - 1)) {
			temp  = v2[j];
			j ++;
		} else if (j > (n2 - 1)) {
			temp = v1[i];
			i ++;
		} else {
			if (v1[i] < v2[j]) {
				temp = v1[i];
				i ++;
			} else {
				temp = v2[j];
				j ++;
			}
		}


		*(new_arr + k) = temp;
	}

	return new_arr;
}
