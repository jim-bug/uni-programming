/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-27
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#define MAX_LEN 50

int string_length(char[]);
void string_copy(char[], char[]);
void string_concat(char[], char[]);
int string_compare(char[], char[]);

int main(void){
	char str1[MAX_LEN + 1], str2[MAX_LEN + 1];

	printf("Inserisci la prima stringa: ");
	scanf("%50[^\n]", str1);

	printf("Inserisci la seconda stringa: ");
	scanf(" %50[^\n]", str2);

	if (!string_compare(str1, str2)) {
		printf("Le stringhe sono uguali!\n");
	}

	printf("Copio %s in %s.\n", str2, str1);
	string_copy(str1, str2);
	printf("Stringa risultante: %s\n", str1);

	string_concat(str1, str2);
	printf("Concatenazione: %s\n", str1);

	return 0;
}

int string_length(char str[]){
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++){
		len++;
	}

	return len;
}

void string_copy(char destination[], char source[]){
	int src_len = string_length(source);

	for (int i = 0; i < src_len; i++){
		destination[i] = source[i];
	}
	destination[src_len] = '\0';
}

void string_concat(char destination[], char source[]){
	int dest_len = string_length(destination);
	int src_len = string_length(source);

    if (dest_len + src_len > MAX_LEN) return;

	for (int i = 0; i < src_len; i++){
		destination[dest_len + i] = source[i];
	}

	destination[dest_len + src_len] = '\0';
}

int string_compare(char str1[], char str2[]){
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i] != '\0'; i++);

	if (str1[i] == '\0'){
		return 0;
	}

	if (str1[i] < str2[i]){
		return -1;
	}

	return 1;
}
