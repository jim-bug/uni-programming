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

int my_strtok(const char*, char, char[][LEN_TOK + 1]);

int main (void){
	char str[MAX_LEN + 1];
	char token[TOKEN][LEN_TOK + 1];
	char sep;

	printf("Inserisci la stringa: ");
	scanf("%100[^\n]", str);

	printf("Inserisci il separatore: ");
	scanf(" %c", &sep);

	int tokens = my_strtok(str, sep, token);
	for (int i = 0; i < tokens; i ++){
			printf("%s\n", token[i]);
	}


	return 0;
}

int my_strtok(const char *string, char sep, char token[][LEN_TOK + 1]){
	int len = strlen(string);
	int j = 0;
	int k = 0;
	for (int i = 0; i < len; i++){
		if (*(string + i) != sep){
			if (j < TOKEN && k < LEN_TOK){		// controllo che non si superi il numero massimo di token e la lunghezza massima di ogni token
				token[j][k] = *(string + i);
				k ++;
			}
		}
		else{
			if (k > 0 && j < TOKEN){			// se ho raggiunto un separatore e ho un token da salvare, lo salvo e passo al successivo
				token[j][k] = '\0';
				j ++;
			}
			k = 0;
		}
	}

	if (k > 0 && j < TOKEN){					// se alla fine della stringa ho un token da salvare, lo salvo
		token[j][k] = '\0';
		j ++;
	}

	return j;
}
