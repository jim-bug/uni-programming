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
#include <ctype.h>

#define MIN_LEN 8
#define MAX_LEN 50

void password_generator(char[], int);
void shuffle(char[], int);                   // dall'esercizio5-2 (adattata)
int valida_password(const char[], int);      // dall'esercizio 4  (adattata)
int search(const char[], char, int);         // dall'esercizio 4  (adattata)

int main(void){
	srand(time(NULL));

	char password[MAX_LEN + 1];
	int len, n;

	do {
		printf("Inserisci la lunghezza della password (tra %d e %d): ", MIN_LEN, MAX_LEN);
		scanf("%d", &len);
	} while (len < MIN_LEN || len > MAX_LEN);

    do {    // inserito solo per scopo di test
		printf("Inserisci il numero di password da generare (> 0): ");
		scanf("%d", &n);
	} while (n <= 0);

    for (int k = 0; k < n; k++){    // inserito solo per scopo di test
        password_generator(password, len);
        printf("%d) Password generata: ", k + 1);
        for (int i = 0; i < len; i++){
            printf("%c", password[i]);
        }
        printf(" esito validazione password: %d\n", valida_password(password, len));
    }

	return 0;
}

void password_generator(char pass[], int len){
    const char UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char LOWER[] = "abcdefghijklmnopqrstuvwxyz";
    const char DIGIT[] = "0123456789";
    const char SPECIALS[] = "!@#$%^&*"; 
	const char ALL[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    int len_all = strlen(ALL);

    // inserisco nelle prime quattro posizioni i caratteri minimi da rispettare
    pass[0] = UPPER[rand() % strlen(UPPER)];
    pass[1] = LOWER[rand() % strlen(LOWER)];
    pass[2] = DIGIT[rand() % strlen(DIGIT)];
    pass[3] = SPECIALS[rand() % strlen(SPECIALS)];

	for (int i = 4; i < len; i++){      // inserisco nelle rimanenti posizioni caratteri presi dall'alfabeto completo
		int index = rand() % len_all;
		pass[i] = ALL[index];
	}

    shuffle(pass, len);                 // "mescolando" la password appena generata non ottengo più un pattern prevedibile

    pass[len] = '\0';
}

void shuffle(char str[], int len){
//    int len = strlen(str);

    for (int i = 0; i < len; i++){
		int k = rand() % (i + 1);		// genero un indice pseudo-casuale da 0 a i

		char temp = str[i];
		str[i] = str[k];
		str[k] = temp;
	}
}

int valida_password (const char pass[], int len){
//	int len = strlen(pass);
	const char SPECIALS[] = "!@#$%^&*";
    int len_specials = strlen(SPECIALS);
	int upper = 0, lower = 0, digit = 0, special = 0;

	for (int i = 0;i < len; i++){
		if (isdigit(pass[i])) digit = 1;
		if (islower(pass[i])) lower = 1;
		if (isupper(pass[i])) upper = 1;
		if (search(SPECIALS, pass[i], len_specials)) special = 1;
	}

	return (len >= 8 && lower && special && upper && digit) ? 1 : 0;
}

int search(const char sequence[], char k, int len) {
//	int len = strlen(sequence);

	for (int i = 0; i < len; i++) {
		if (k == sequence[i]) return 1;
	}

	return 0;
}
