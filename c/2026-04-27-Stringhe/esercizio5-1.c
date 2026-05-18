/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-29
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 50000

int search(int[], int, int);
int tombola(int[], int);

int main(void){
	srand(time(NULL));

	int array[LEN];

	int count = tombola(array, LEN);
	for (int i = 0; i < LEN; i++){
		printf("%d\t", array[i]);
		if( (i + 1) % 10 == 0) printf("\n");		// disposizione numeri in tabella  	
	}

	printf("\nLa funzione rand() è stata chiamata %d volte\n", count);

	return 0;
}

int tombola(int arr[], int len){
	int count = 0;
	for (int i = 0; i < len; ){
		int temp = 1 + rand() % (len);
		if (!search(arr, temp, i)){
			arr[i] = temp;
			i ++;
		}
		count ++;
	}

	return count;
}

int search(int sequence[], int k, int len) {
	for (int i = 0; i < len; i++) {
		if (k == sequence[i]) return 1;
	}

	return 0;
}
