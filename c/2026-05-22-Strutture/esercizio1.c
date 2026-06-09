/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-22
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>


#define MAX 10
#define LEN_TIPI 5

typedef struct Ingrediente {
	char nome[100];
	double dose;
} Ingrediente;

typedef struct Pietanza {
	char nome[100];
	Ingrediente ingredienti[MAX];
	double tempo;
	char tipo[100];
} Pietanza;


void stampa(Pietanza, int);

int main(void) {
	const char* TIPI[LEN_TIPI] = {"Antipasto", "Primo", "Secondo", "Contorno", "Dolce"};
	int n, index;
	Pietanza pietanza;

	do {
		printf("Inserisci il numero di ingredienti della pietanza (0-%d): ", MAX);
		scanf("%d", &n);
	} while (n < 0 || n > MAX);

	printf("Inserisci il nome della pietanza: ");
	scanf(" %100[^\n]", pietanza.nome);

	for (int i = 0; i < n; i++) {
		Ingrediente ingrediente;
		printf("Inserisci il nome dell'ingrediente: ");
		scanf(" %100[^\n]", ingrediente.nome);

		printf("Inserisci la dose (in g) dell'ingrediente: ");
		scanf(" %lf", &ingrediente.dose);

		pietanza.ingredienti[i] = ingrediente;
	}

	printf("\nInserisci il tempo di cottura della pietanza: ");
	scanf(" %lf", &pietanza.tempo);
	printf("Inserisci il tipo di pietanza: \n");
	do{
		for (int i = 0; i < LEN_TIPI; i++){
			printf("%d) %s\n", i, TIPI[i]);
		}
	
	
		printf("Scelta: ");
		scanf(" %d", &index);
	} while (index < 0 || index >= LEN_TIPI);

	strcpy(pietanza.tipo, TIPI[index]);
	
	stampa(pietanza, n);
}

void stampa(Pietanza pietanza, int n){
	printf("Nome: %s\n", pietanza.nome);
	printf("Ingredienti: \n\n\n");
	for (int i = 0; i < n; i++) {
		printf("%d) Nome: %s, Dose: %f\n", i + 1, pietanza.ingredienti[i].nome, pietanza.ingredienti[i].dose);

	}

	printf("\n\nTempo di cottura: %f\n", pietanza.tempo);
	printf("Tipo di piatto: %s\n\n", pietanza.tipo);
}
