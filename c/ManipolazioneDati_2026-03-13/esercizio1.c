/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-13
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int main(void) {
	float celsius;
	float fahrenheit;
	float kelvin;
	
	printf("Inserisci i gradi in celsius: ");
	scanf("%f", &celsius);

	fahrenheit = celsius * 9/5 + 32;
	kelvin = celsius + 273.15;

	printf("Gradi in Fahrenheit: %.2f\nKelvin: %.2f\n", fahrenheit, kelvin);

	return 0;
}
