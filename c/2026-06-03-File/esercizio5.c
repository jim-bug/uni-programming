/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-06-03
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN_NAME_AUTHOR 50
#define MAX_LEN_SURNAME_AUTHOR 30
#define MAX_LEN_TITLE 100
#define MAX_BOOK 500

typedef struct Libro{
	char name[MAX_LEN_NAME_AUTHOR + 1];
	char surname[MAX_LEN_SURNAME_AUTHOR + 1];
	char title[MAX_LEN_TITLE + 1];
	int n_page;
	int n_chapter;
} Libro;

Libro* get_book_with_longest_chapters(Libro[], size_t);

int main(int argc, char* argv[]){
	if (argc < 2){
		printf("Use %s file.\n", argv[0]);
		return -1;
	}

	FILE* input;

	if ((input = fopen(argv[1], "r")) == NULL){
		printf("Errore nell'apertura del file.\n");
		return -1;
	}

	size_t n_book;
	size_t i = 0;
	char name[MAX_LEN_NAME_AUTHOR + 1];
	char surname[MAX_LEN_SURNAME_AUTHOR + 1];
	char title[MAX_LEN_TITLE + 1];
	int n_page;
	int n_chapter;

	if (fscanf(input, "%zu", &n_book) != 1){
		printf("File non valido.\n");
		fclose(input);
		return -1;
	}

	if (n_book > MAX_BOOK){
		n_book = MAX_BOOK;
	}

	Libro libri[MAX_BOOK];

	while(i < n_book && fscanf(input, " %100[^,],%50[^,],%30[^,],%d,%d", title, name, surname, &n_page, &n_chapter) == 5){
		strcpy(libri[i].name, name);
		strcpy(libri[i].surname, surname);
		strcpy(libri[i].title, title);
		libri[i].n_page = n_page;
		libri[i].n_chapter = n_chapter;

		i ++;
	}

	if (i == 0){
		printf("Nessun libro letto.\n");
		fclose(input);
		return -1;
	}

	Libro* max = get_book_with_longest_chapters(libri, i);

	printf("Il nome del libro con i capitoli più lunghi è: %s.\n", max->title);

	fclose(input);

	return 0;
}

Libro* get_book_with_longest_chapters(Libro libri[], size_t len){
	double max = (double)libri[0].n_page / (double)libri[0].n_chapter;
	Libro* max_book = &libri[0];

	for(size_t i = 1; i < len; i++){
		double value = (double)libri[i].n_page / (double)libri[i].n_chapter;
		if(value > max) {
			max = value;
			max_book = &libri[i];
		}
	}
	return max_book;
}
