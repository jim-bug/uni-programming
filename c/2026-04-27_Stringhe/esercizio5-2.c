/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-29
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 1000000


int shuffle(int[], int);
void initialize(int[], int);

int main(void){
	srand(time(NULL));

	int array[LEN];

	initialize(array, LEN);
	int count = shuffle(array, LEN);
	for (int i = 0; i < LEN; i++){
		printf("%d\t", array[i]);
		if( (i + 1) % 10 == 0) printf("\n");		// disposizione numeri in tabella  	
	}

	printf("\nLa funzione rand() è stata chiamata %d volte\n", count);

	return 0;
}

void initialize(int arr[], int len){
	for (int i = 0; i < len; i++){
		arr[i] = i;
	}
}

int shuffle(int arr[], int len){
	int count = 0;
	for (int i = 0; i < len; i++){
		int k = rand() % (i + 1);		// genero un indice pseudo-casuale da 0 a i

		int temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
		count ++;
	}

	return count;
}
