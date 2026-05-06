/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-06
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>

#define LEN_TOK 20
#define TOKEN 10

int my_strtok(const char*, char, char[][LEN_TOK]);

int main (void){


	char str[] = "Uno Due Tre Quattro Cinque Sei Sette Otto Nove Dieci";
	char token[TOKEN][LEN_TOK];

	int a = my_strtok(str, ' ', token);
	for (int i = 0; i < a; i ++){
			printf("%s\n", token[i]);
	}

	return 0;
}

int my_strtok(const char *string, char sep, char token[][LEN_TOK]){
	int len = strlen(string);
	int j = 0;
	int k = 0;
	for (int i = 0; i < len; i++){
		if (*(string + i) != ' '){
			token[j][k] = *(string + i);
			k ++;
		}
		else{
			j ++;
			k = 0;
		}
	}
	return j+1;
}
