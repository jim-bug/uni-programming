/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-04-13
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int secondoMassimo(int[], int);
// int controlloDistinti(int[], int);

int main(void){
    int n, temp;
    
    do {
        printf("Inserisci la lunghezza della sequenza (> 0): ");
        scanf("%d", &n);
    } while (n < 2);

    int arr[n];

// do {
        for(int i = 0; i < n; i++){
            int duplicato;
            do {        // migliore gestione in caso di valori duplicati
                duplicato = 0;
                printf("Inserisci l'elemento della sequenza alla posizione %d (distinto rispetto agli altri inseriti): ", i+1);
                scanf("%d", &temp);

                for (int j = 0; j < i; j++) {
                    if (arr[j] == temp){
                        duplicato = 1;
                        break;
                    }
                }

                if (!duplicato) {
                    arr[i] = temp;
                }

            } while (duplicato);

        }
// } while (controlloDistinti(arr, n) == 0);

    printf("Il secondo massimo della sequenza inserita è: %d\n", secondoMassimo(arr, n));

    return 0;
}

// int controlloDistinti(int vet[], int n){
//     for(int i = 0; i < n - 1; i++){
//         for (int j = i + 1; j < n; j++){
//             if (vet[i] == vet[j]){
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }

int secondoMassimo(int v[], int n){
    int max, secondo_max;

    if (v[0] > v[1]){
        max = v[0];
        secondo_max = v[1];
    } else {
        max = v[1];
        secondo_max = v[0];
    }

    for(int i = 2;i < n; i++){
        if(v[i] > max){
            secondo_max = max;
            max = v[i];
        } else if (v[i] > secondo_max && v[i] != max) {
            secondo_max = v[i];
        }
    }

    return secondo_max;
}
