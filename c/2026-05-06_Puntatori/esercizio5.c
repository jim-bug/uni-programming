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
#define MAX_LEN 100

int my_strtok(const char*, char, char[][LEN_TOK]);

int main (void){
	char str[MAX_LEN];
	char token[TOKEN][LEN_TOK];


	printf("Inserisci la stringa: ");
	scanf("%100[^\n]", str);

	int tokens = my_strtok(str, ' ', token);
	for (int i = 0; i < tokens; i ++){
			printf("%s\n", token[i]);
	}


	return 0;
}

int my_strtok(const char *string, char sep, char token[][LEN_TOK]){
	int len = strlen(string);
	int j = 0;
	int k = 0;
	for (int i = 0; i < len; i++){
		if (*(string + i) != sep){
			token[j][k] = *(string + i);
			k ++;
		}
		else{
			token[j][k] = '\0';
			j ++;
			k = 0;
		}
	}

	token[j][k] = '\0';
	return j + 1;
}
