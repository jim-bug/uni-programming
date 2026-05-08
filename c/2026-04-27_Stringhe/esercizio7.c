/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-29
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define ALPHABET_LEN 26

int verify(const char[], const char[]);

int main(void){
    char str1[MAX_LEN + 1], str2[MAX_LEN + 1];

    printf("Inserisci la prima stringa: ");
    scanf("%100[^\n]", str1);

    printf("Inserisci la seconda stringa: ");
    scanf(" %100[^\n]", str2);
    
    
    printf("Le stringhe %s e %s %ssono anagrammi\n",str1, str2, verify(str1, str2) ? "" : "non ");
    
    return 0;
}


int verify(const char str1[], const char str2[]){
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    int supp[ALPHABET_LEN] = {0};

    for (int i = 0;i < len_str1; i++){
        if (str1[i] >= 'a' && str1[i] <= 'z') supp[str1[i] - 'a'] ++;
    }

    for (int i = 0; i < len_str2; i++){
		if (str2[i] >= 'a' && str2[i] <= 'z') supp[str2[i] - 'a'] --;
    }

    for (int i = 0; i < ALPHABET_LEN; i++){
        if (supp[i]) return 0;
    }

    return 1;
}
