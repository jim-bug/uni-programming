/*
* 	Autore: Ignazio Leonardo Calogero Sperandeo
* 	Data: 2026-03-20
* 	Consegna: Rif. README.md
* 	by jimbug // :)
*/

#include <stdio.h>

int main(void) {
	int op;
	printf("Scegli tra una delle operazione che seguono: \n\t1) Valore assoluto di un numero\n\t2) Operazioni aritmetiche base \n\t3) Scambio di due variabili\n");
	scanf("%d", &op);

	switch (op) {
		case 1: {
			int x;
			printf("Inserisci il valore di x: \n");
			scanf("%d", &x);
			x = x >= 0 ? x : -x;
			printf("Valore assoluto di x: %d\n", x);
			break;
		}
		case 2: {
			int operazione;
			float a, b;
			printf("Inserisci un operatore tra i presenti: \n\t 1) + \n\t 2) -\n\t 3) *\n\t 4) /\n");
			scanf("%d", &operazione);
			printf("Inserisci il valore di a: ");
			scanf("%f", &a);
			printf("Inserisci il valore di b: ");
			scanf("%f", &b);
			switch (operazione) {
				case 1:
					printf("La somma di %.2f e %.2f è: %.2f\n", a, b, a+b);
					break;
				case 2: 
					printf("La sottrazione di %.2f e %.2f è: %.2f\n", a, b, a-b);
						break;
				case 3: 
					printf("La moltiplicazione di %.2f e %.2f è: %.2f\n", a, b, a*b);
					break;
				case 4:
					if (b == 0) {
						printf("Operazione non possibile, si inserisca una combinazione di numeri valida!\n");
						return -1;
					} 
					printf("La divisione tra %.2f e %.2f è: %.2f\n", a, b, a/b);
					break;
				default:
					printf("Operazione non valida, inserire un operazione tra quelle presenti.\n");
					break;
			}
			break;
		}
		case 3: {
			int x, y, temp;
			printf("Inserisci il valore di x: \n");
			scanf("%d", &x);
			printf("Inserisci il valore di y: \n");
			scanf("%d", &y);
			temp = x;
			x = y;
			y = temp;
			
			printf("Valori di x: %d e y: %d scambiati\n", x, y);
			break;
		}
		default:
			printf("Operazione non consentita, inserire un operazione tra quelle presenti.\n");
			break;

	}

	return 0;
}




