/*
*   Autore: Ignazio Leonardo Calogero Sperandeo
*   Data: 2026-03-30
*   Consegna: Rif. README.md
*   by jimbug // :)
*/

#include <stdio.h>

int find_pattern(int[], int[], int, int);
int main(void){
	int pattern_length, sequence_length;

	do {
		printf("Inserisci la lunghezza della sequenza (> 0): ");
		scanf("%d", &sequence_length);
	} while (sequence_length <= 0);

	do {
		printf("Inserisci la lunghezza della sequenza da cercare (> 0 e minore della sequenza generale): ");
		scanf("%d", &pattern_length);
	} while (pattern_length <= 0 || pattern_length >= sequence_length);


	int sequence[sequence_length], pattern[pattern_length];
	
	for (int i = 0; i < sequence_length; i++){
		printf("Inserisci l'elemento della sequenza alla posizione %d: ", i);
		scanf("%d", &sequence[i]);
	}

	for (int i = 0; i < pattern_length; i++){
		printf("Inserisci l'elemento del pattern alla posizione %d: ", i);
		scanf("%d", &pattern[i]);
	}


	int index = find_pattern(sequence, pattern, sequence_length, pattern_length);
	printf("Il pattern %s presente nella sequenza e si trova alla posizione: %d\n", index == -1 ? "non è" : "è", index);



	return 0;
}

int find_pattern(int sequence[], int pattern[], int sequence_length, int pattern_length){
	for (int i = 0; i < sequence_length; i++){
		int j;
		for (j = 0; j <= sequence_length - pattern_length; j++){
			if (sequence[i + j] != pattern[j]){
				break;
			}
		}
		if (j == pattern_length) {
			return i;
		}
	}
	return -1;
}
