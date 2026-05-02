/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-29
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int valida_password(const char[]);
int search(char, const char[]);

int main(void){
	char str1[MAX_LEN + 1];

	printf("Inserisci la stringa: ");
	scanf("%100[^\n]", str1);


	printf("La passoword risulta %s valida\n", valida_password(str1) ? "valida" : "non valida");

	return 0;
}


int valida_password (const char pass[]){
	int len = strlen(pass);
	const char SPECIALS[] = "!@#$%^&*";
	int upper = 0, lower = 0, digit = 0, special = 0;

	for (int i = 0;i < len; i++){			// metodo alternativo: usare strpbrk()
		if (isdigit(pass[i])) digit = 1;
		if (islower(pass[i])) lower = 1;
		if (isupper(pass[i])) upper = 1;
		if (search(pass[i], SPECIALS)) special = 1;
	}

	return (len >= 8 && lower && special && upper && digit) ? 1 : 0;
}

int search(char k, const char sequence[]) {
	int len = strlen(sequence);

	for (int i = 0; i < len; i++) {
		if (k == sequence[i]) return 1;
	}

	return 0;
}
