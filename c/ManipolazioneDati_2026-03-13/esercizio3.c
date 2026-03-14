/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-13
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int main(void){
	int centesimi;
	int moneta50;
	int moneta20;
	int moneta10;
	int moneta5;
	int moneta2;
	int resto;

	printf("Inserisci il numero di centesimi: ");
	scanf("%d", &centesimi);
	
	resto = centesimi;
	// printf("%d ", centesimi);

	moneta50 = centesimi / 50;
	resto %= 50;
	moneta20 = resto / 20;
	resto %= 20;
	moneta10 = resto / 10;
	resto %= 10;
	moneta5 = resto / 5;
	resto %= 5;
	moneta2 = resto / 2;
	resto %= 2;			// il numero di monete da 1 centesimi è contenuto nella variabile resto, considerate le riassegnazioni

	printf("%d centesimi = %d monete da 50 + %d monete da 20 + %d monete da 10 + %d monete da 5 + %d monete da 2 + %d monete da 1\n", centesimi, moneta50, moneta20, moneta10, moneta5, moneta2, resto);	

	return 0;
}
