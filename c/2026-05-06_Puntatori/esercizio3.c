/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-06
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_LEN 100

int my_atoi(const char[]);

int main (void){

	char str[MAX_LEN + 1];
	
	printf("Inserisci la stringa: ");
	scanf("%100[^\n]", str);

	printf("Numero corrispondente: %d\n", my_atoi(str));

	return 0;

}

int my_atoi(const char str[]){
	double number = 0;
	int len = strlen(str);

	for (int i = len-1; i >= 0; i --){
		if (isdigit(str[i])){
			number += (str[i] - '0') * pow(10.0, (double) len - 1 - i);
		}
	}

	if (str[0] == '-') return - (int) number;
	return (int) number;
}
