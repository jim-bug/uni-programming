/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-13
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int main(void){
	char character;
	int shift;

	printf("Inserisci il carattere: ");
	scanf("%c", &character);
	printf("Inserisci lo spostamento: ");
	scanf("%d", &shift);

	printf("Carattere spostato con assegnazione circolare: %c\n", (character - 'A' + shift) % 26 + 'A');	
	
		
	return 0;
}
