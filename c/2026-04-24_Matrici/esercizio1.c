/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-04-24
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#define N 5
#define M 5

int check_array(int[], int[], int);


int main(void){
	int mat1[N][M] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	int mat2[N][M] = {{1,2,4,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

	for (int i = 0;i < N; i ++){
		if (!check_array(mat1[i], mat2[i], M)){
			printf("Le due matrici non sono uguali\n");
			return 0;
		}
	}

	printf("Le matrici sono uguali!\n");

	return 0;
}

int check_array(int arr[], int arr1[], int n){
	for (int i = 0;i < n; i++){
		if (arr[i] != arr1[i]){
			return 0;
		}
	}
	return 1;
}
