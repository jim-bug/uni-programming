/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-03-30
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

void initialize_array(int[], int);
void find_primes(int[], int);
int main(void){
	int length = 1000;
	int prime_count = 0;
	int numbers[length];

	find_primes(numbers, length);

	for(int i = 2; i < length; i++){
		if(numbers[i]) {
			printf("%d) %d\n", prime_count+1, i);
			prime_count++;
		}
	}

	return 0;
}

void initialize_array(int values[], int length){
	for (int i = 0; i < length; i++){
		values[i] = 1;
	}

}



void find_primes(int values[], int length){
	initialize_array(values, length);
	for (int i = 2; i < length; i++){	// i sarebbe il candidato a numero primo
		if (values[i]) {
			for (int j = i; j * i < length; j++){
				values[j * i] = 0;
			}
		}
	}

}
