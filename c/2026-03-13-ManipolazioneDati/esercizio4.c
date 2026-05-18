/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-13
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int main(void){
	int num;
	int centinaia;
	int decina;
	int resto;
	printf("Inserisci il numero (tra 100 e 999): ");
	scanf("%d", &num);
	resto = num;
	
	centinaia = num / 100;
	resto %= 100;
	decina = resto / 10;
	resto %= 10;
	
	printf("%d -> Centinaia: %d, Decina: %d, Unita: %d\n", num, centinaia, decina, resto);
		
	return 0;
}
