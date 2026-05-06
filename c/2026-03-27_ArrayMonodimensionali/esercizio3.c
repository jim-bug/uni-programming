/*
*   Autore: Ignazio Leonardo Calogero Sperandeo
*   Data: 2026-03-30
*   Consegna: Rif. README.md
*   by jimbug // :)
*/

#include <stdio.h>


void separate_digits(int[], int, int);
int is_palindrome(int[], int);

int main(void){
	int number, len = 5;
	int decomposed_number[len];

	do {
		printf("Inserisci un numero di %d cifre: ", len);
		scanf("%d", &number);
	} while (number < 10000 || number > 99999);


	separate_digits(decomposed_number, len, number);
	printf("Il numero %d %s palindromo!\n", number, is_palindrome(decomposed_number, len) ? "è" : "non è");


	return 0;
}

void separate_digits(int digits[], int count, int number){

	for (int i = 0;i < count; i++){
		digits[i] = number % 10;
		number /= 10;
	}

}

int is_palindrome(int digits[], int size) {

	int half_size = size/2;		// numero di controlli da fare
	for (int i = 0; i < half_size; i++){
		if (digits[i] != digits[size - 1 - i]){
			return 0;
		}

	}
	return 1;

}
