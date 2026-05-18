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

int my_atoi(const char str[]) {
    int i = 0;
    int sign = 1;
    int number = 0;

    while (isspace((unsigned char)str[i])) {	// ignoro spazi iniziali
        i++;
    }

    if (str[i] == '-' || str[i] == '+') {		// gestisco eventuale segno
        if (str[i] == '-') {
            sign = -1;
        }
        i++;
    }

    while (isdigit((unsigned char)str[i])) {	// converto i caratteri numerici in intero
        number = number * 10 + (str[i] - '0');
        i++;
    }

    return sign * number;
}

