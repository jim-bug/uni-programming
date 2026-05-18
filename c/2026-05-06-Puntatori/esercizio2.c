/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-06
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

char* find_char(char[], char);

int main (void){

	char str[MAX_LEN + 1];
	char k;
	
	printf("Inserisci la stringa: ");
	scanf("%100[^\n]", str);
	
	printf("Inserisci l'elemento da cercare: ");
	scanf(" %c", &k);

	char *found = find_char(str, k);
	
	printf("Il carattere %c %s stato nella stringa: %s1n", k, found != NULL ? "è" : "non è", str);


	if (found != NULL){
		// procedo a modificare found:
		*found = 'P';
		printf("Stringa dopo la modifica del carattere trovato: %s", str); 
	}

	return 0;
}

char* find_char(char str[], char k){
	int len = strlen(str);
	for (int i = 0; i < len; i++){
		if (str[i] == k) return &str[i];
	}

	return NULL;
}
