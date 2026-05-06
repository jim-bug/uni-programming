/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-13
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int main(void){
	float distance;
	int hour;
	int minute;
	float time;
	float speed;	


	printf("Inserisci la distanza percorsa (Km): ");
	scanf("%f", &distance);
	printf("Inserisci il numero di ore totali: ");
	scanf("%d", &hour);
	printf("Inserisci il numero di minuti totali: ");
	scanf("%d", &minute);
	
	time = hour + minute/60.0;
	speed = distance / time;
	
	printf("Velocita media: %.2f Km/h\n", speed);	

	return 0;
}
