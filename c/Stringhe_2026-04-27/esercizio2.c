/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-27
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

// int count_upper_letters(char[]);
// int count_lower_letters(char[]);
// int count_digits(char[]);
int count_chars(char[], char, char);

int main(void){
	int upper_letters, lower_letters, digits;
	char str1[MAX_LEN + 1];

	printf("Inserisci la prima stringa: ");
	scanf("%100[^\n]", str1);

	upper_letters = count_chars(str1, 'A', 'Z');
	lower_letters = count_chars(str1, 'a', 'z');
	digits = count_chars(str1, '0', '9');

	printf("Nella stringa %s sono presenti:\n\t1) Lettere Maiuscole: %d\n\t2) Lettere Minuscole: %d\n\t3) Cifre: %d\n\t4) Resto: %d\n", str1, upper_letters, lower_letters, digits, (int)strlen(str1) - upper_letters - lower_letters - digits);

	return 0;
}

int count_chars(char str[], char min, char max){
    // int len = strlen(str);
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] >= min && str[i] <= max){
			count ++;
		}
	}

	return count;
}
