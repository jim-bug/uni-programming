/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-13
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int my_strlen(char[]);

int main(void) {
	char str[MAX_LEN + 1];
	printf("Inserisci la stringa (max 100 caratteri): ");
	scanf("%100[^\n]", str);

	printf("La lunghezza della stringa %s è: %d\n", str, my_strlen(str));

	return 0;

}

int my_strlen(char str[]){
	if (*str == '\0') return 0;

	return my_strlen(str+1) + 1;
}


