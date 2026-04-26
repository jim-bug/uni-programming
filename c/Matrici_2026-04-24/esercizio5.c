/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-04-24
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>

void generate_matrix(int n, int[][n]);
void print_matrix(int n, int [][n]);

int main(void){

	int n;

	do {
		printf("Inserisci la dimensione della matrice (> 0): ");
		scanf("%d", &n);
	} while (n <= 0);

	int mat[n][n];

	printf("Matrice risultante con n = %d:\n", n);

	generate_matrix(n, mat);
	print_matrix(n, mat);

	return 0;
}

void generate_matrix(int n, int mat[][n]){

	int top = 0, bottom = n - 1;
	int left = 0, right = n - 1;
	int num = 1;

	// riempio la matrice per anelli concentrici in senso orario

	while (top <= bottom && left <= right){

		// riga superiore: da sinistra a destra
		for (int j = left; j <= right; j++){
			mat[top][j] = num++;
		}
		top++;

		// colonna destra: dall'alto verso il basso
		for (int i = top; i <= bottom; i++){
			mat[i][right] = num++;
		}
		right--;

		// riga inferiore: da destra a sinistra (se ancora valida)
		if (top <= bottom){
			for (int j = right; j >= left; j--){
				mat[bottom][j] = num++;
			}
			bottom--;
		}

		// colonna sinistra: dal basso verso l'alto (se ancora valida)
		if (left <= right){
			for (int i = bottom; i >= top; i--){
				mat[i][left] = num++;
			}
			left++;
		}
	}
}

void print_matrix(int n, int mat[][n]){

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}