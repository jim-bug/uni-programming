/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-02
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>


int countCombinazioni(int[], int, int);
int main(void) {
    int n, S;
    do {
        printf("Inserisci la lunghezza della sequenza (> 0): ");
        scanf("%d", &n);
    } while (n <= 0);

    int array[n];

    printf("Inserisci il valore della somma: ");
    scanf("%d", &S);

    for (int i = 0; i < n; i++){
        printf("Inserisci il valore alla posizione %d della sequenza: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Il numero di coppie presente nella sequenza la cui somma fa %d sono %d\n", S, countCombinazioni(array, n, S));
    
    return 0;
}

int countCombinazioni(int vett[], int n, int S) {
    int count = 0;
    int size = n - 1;
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < n; j++){
            if ((vett[i] + vett[j]) == S){
                count ++;
            }
        }
    }

    return count;
}
