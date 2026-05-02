/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-29
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LEN 8
#define MAX_LEN 50

void password_generator(char[], int);

int main(void){
	srand(time(NULL));
	
	char password[MAX_LEN + 1];
	int len;

	do {
		printf("Inserisci la lunghezza della password (tra 8 e 50): ");
		scanf("%d", &len);
	} while (len < MIN_LEN || len > MAX_LEN);


	password_generator(password, len);
	printf("Password generata: ");
	for (int i = 0; i < len; i++){
		printf("%c", password[i]);
	}
	printf("\n");


	return 0;
}

void password_generator(char pass[], int len){
	const char ALL[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
	int len_all = strlen(ALL);

	for (int i = 0; i < len; i++){
		int index = rand() % len_all;
		pass[i] = ALL[index];
	}
}
