/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-29
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int palindrome(const char[]);

int main(void){
	char str1[MAX_LEN + 1];

	printf("Inserisci la stringa: ");
	scanf("%100[^\n]", str1);


	printf("La stringa %s %s palindromo\n", palindrome(str1) ? "è" : "non è");

	return 0;
}

int palindrome(const char str[]){
	int len = strlen(str);
	int left = 0, right = len - 1;

	while (left <= right) {
		
		if (str[left] == ' ') {
			left ++;
			continue;
		} 
		if (str[right] == ' '){
			right --;
			continue;
		}
		
		// printf("[%c] == [%c] | %d : %d\n", str[left], str[right], left, right);
		if (str[left] != str[right]) return 0;

		left ++;
		right --;
	}

	return 1;
}
