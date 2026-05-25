/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-22
*	Consegna: Rif. README.md
*	by jimbug // :)
*/



/*
	TRACCIATO RECORD FILE
	Formato:
	Nome Pietanza|Tipo|Tempo|Numero Ingredienti|Nome Ingrediente: Dose; Nome Ingrediente: Dose; ...
	Note:
	- Separatore campi: '|'
	- Separatore ingredienti: ';'
	- Separatore nome/dose: ':'
	- Spazi consentiti attorno a ':'
	- Dose espressa in grammi (g)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_INGREDIENTI 10
#define MAX_LEN_ING 500		// vincolo da file
#define MAX_LEN_ING_NAME 100
#define MAX_LEN_NAME 100
#define MAX_LEN_TYPE 50
#define MAX_PIETANZE 1000
#define TYPES_LEN 5

const char* TIPI[TYPES_LEN] = {"Antipasto", "Primo", "Secondo", "Contorno", "Dolce"};

typedef struct Ingrediente {
	char nome[MAX_LEN_NAME];
	double dose;
} Ingrediente;

typedef struct Pietanza {
	char nome[MAX_LEN_NAME];
	Ingrediente ingredienti[MAX_INGREDIENTI];
	double tempo;
	int numero_ingredienti;
	char tipo[MAX_LEN_TYPE];
} Pietanza;

typedef struct Ricettario {
	Pietanza pietanze[MAX_PIETANZE];
	int numero_pietanze;
} Ricettario;

void print_menu();
void insert(Ricettario*, FILE*, int);
void view_by_pietanza(Ricettario*, char[]);
void view_by_type(Ricettario*, char[]);
void view_by_ingrediente(Ricettario*, Ingrediente);
void view_by_time(Ricettario*, double);
void set_pietanze_from_file(FILE*, Ricettario*);

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Uso: %s <file>\n", argv[0]);
		return -1;
	}

	FILE *fp;
	if ((fp = fopen(argv[1], "r+")) == NULL){
		printf("Impossibile aprire il file\n");
		return -1;
	}

	Ricettario ricettario;
	set_pietanze_from_file(fp, &ricettario);

	int opzione, last = ricettario.numero_pietanze;

	do {
		print_menu();
		printf("Opzione scelta: ");
		scanf("%d", &opzione);

		switch(opzione){
			case 1:
				insert(&ricettario, fp, last);
				last ++;
				ricettario.numero_pietanze = last;

				break;
			case 2: {
				char nome[MAX_LEN_NAME];
				printf("Inserisci il nome della pietanza da ricercare: ");
					scanf(" %99[^\n]", nome);
				view_by_pietanza(&ricettario, nome);

				break;
			}
			case 3: {
				char tipo[MAX_LEN_TYPE];
				printf("Inserisci il nome del tipo di pietanza da ricercare: ");
					scanf(" %99[^\n]", tipo);
				view_by_type(&ricettario, tipo);

				break;
			}
			case 4: {
				Ingrediente ingrediente;

				printf("Inserisci il nome dell'ingrediente da ricercare: ");
				scanf(" %99[^\n]", ingrediente.nome);
				printf("Inserisci la dose dell'ingrediente della pietanza da ricercare: ");
				scanf(" %lf", &ingrediente.dose);
				view_by_ingrediente(&ricettario, ingrediente);

				break;
			}
			case 5: {
				double tempo;
				printf("Inserisci il tempo di cottura soglia: ");
				scanf(" %lf", &tempo);
				view_by_time(&ricettario, tempo);

				break;
			}
			case 6:
				printf("Uscita da programma ...\n")
				break;
			default:
				printf("Opzione non valida!\n");
				break;
		}
	} while(opzione != 6);

    fclose(fp);

	return 0;
}

void print_menu(){
	printf("\n\t\t\t\tBENVENUTO NEL MENU\n");
	printf("1) Inserisci una nuova pietanza.\n");
	printf("2) Visualizzare gli ingredienti e le dosi di una pietanza "
		"(nome inserito da tastiera).\n");
	printf("3) Visualizzare l'elenco delle pietanze in base alla tipologia "
		"(es. antipasti, primi).\n");
	printf("4) Visualizzare il nome delle pietanze che contengono un certo "
		"ingrediente.\n");
	printf("5) Visualizzare l'elenco delle pietanze con tempo di cottura "
		"minore di un valore.\n");
	printf("6) Esci\n");
}

void insert(Ricettario* ricettario, FILE* fp, int i){
	if (i >= MAX_PIETANZE) {
		printf("\nNumero massimo di pietanze raggiunto.\n");
		return;
	}
	int index;

	printf("Inserisci il numero di ingredienti della pietanza: ");
	scanf("%d", &ricettario->pietanze[i].numero_ingredienti);

	printf("Inserisci il nome della pietanza: ");
	scanf(" %99[^\n]", ricettario->pietanze[i].nome);


	for (int j = 0; j < ricettario->pietanze[i].numero_ingredienti; j++) {
		Ingrediente ingrediente;
		printf("Inserisci il nome dell'ingrediente: ");
		scanf(" %99[^\n]", ingrediente.nome);

		printf("Inserisci la dose (in g) dell'ingrediente: ");
		scanf(" %lf", &ingrediente.dose);

		ricettario->pietanze[i].ingredienti[j] = ingrediente;
	}

	printf("\nInserisci il tempo di cottura della pietanza: ");
	scanf(" %lf", &ricettario->pietanze[i].tempo);
	printf("Inserisci il tipo di pietanza: \n");
	do{
		for (int i = 0; i < LEN_TIPI; i++){
			printf("%d) %s\n", i, TIPI[i]);
		}
	
	
		printf("Scelta: ");
		scanf(" %d", &index);
	} while (index < 0 || index >= LEN_TIPI);

	strcpy(ricettario->pietanze[i].tipo, TIPI[index]);


	// scrittura nel file del record
    fprintf(fp, "%s|%s|%.1f|%d|", ricettario->pietanze[i].nome, ricettario->pietanze[i].tipo, ricettario->pietanze[i].tempo, ricettario->pietanze[i].numero_ingredienti);
    for (int j = 0; j < ricettario->pietanze[i].numero_ingredienti; j++) {
        fprintf(fp, "%s: %.1f", ricettario->pietanze[i].ingredienti[j].nome, ricettario->pietanze[i].ingredienti[j].dose);
        if (j + 1 < ricettario->pietanze[i].numero_ingredienti) {
            fprintf(fp, ";");
        }
    }
    fprintf(fp, "\n");

}

void view_by_pietanza(Ricettario* ricettario, char nome[]){
	for (int i = 0; i < ricettario->numero_pietanze; i++){
		if (!strcmp(ricettario->pietanze[i].nome, nome)){
			printf("\n\nIngredienti di: %s:", ricettario->pietanze[i].nome);
			for (int j = 0; j < ricettario->pietanze[i].numero_ingredienti; j ++)
				printf("\t%d) Ingrediente: %s | Dose: %lf g\n", j + 1, ricettario->pietanze[i].ingredienti[j].nome, ricettario->pietanze[i].ingredienti[j].dose);
			break;
		}
	}
	printf("\n");
}

void view_by_type(Ricettario* ricettario, char tipo[]){
	printf("\n\nElenco dei %s:\n", tipo);
	for (int i = 0; i < ricettario->numero_pietanze; i++){
		if (!strcmp(ricettario->pietanze[i].tipo, tipo)){
			printf("\t%d) Nome Pietanza: %s\n", i + 1, ricettario->pietanze[i].nome);
		}
	}
	printf("\n");
}

void view_by_ingrediente(Ricettario* ricettario, Ingrediente ingrediente){
	for (int i = 0; i < ricettario->numero_pietanze; i++){
		for (int j = 0; j < ricettario->pietanze[i].numero_ingredienti; j++){
			if (!strcmp(ricettario->pietanze[i].ingredienti[j].nome, ingrediente.nome) && ricettario->pietanze[i].ingredienti[j].dose == ingrediente.dose){
				printf("\t%d) Nome Pietanza: %s\n", i + 1, ricettario->pietanze[i].nome);
				break;
			}
		}
	}
}

void view_by_time(Ricettario* ricettario, double time){
	printf("\n\n");
	for (int i = 0; i < ricettario->numero_pietanze; i++){
		if(ricettario->pietanze[i].tempo < time){
			printf("\t%d) Nome Pietanza: %s\n", i + 1, ricettario->pietanze[i].nome);
		}
	}
}

void set_pietanze_from_file(FILE* fp, Ricettario* ricettario){
	// lettura da file e caricamento nella struttura in memoria

	char nome[MAX_LEN_NAME];
	char tipo[MAX_LEN_TYPE];
	char ingredienti[MAX_LEN_ING];
	double tempo;
	int numero_ingredienti;
	int index = 0;

	while (index < MAX_PIETANZE && fscanf(fp, " %99[^|]|%99[^|]|%lf|%d|%499[^\n]", nome, tipo, &tempo, &numero_ingredienti, ingredienti) == 5) {
		Pietanza temp;
		strcpy(temp.nome, nome);
		strcpy(temp.tipo, tipo);
		temp.tempo = tempo;
		temp.numero_ingredienti = numero_ingredienti;
        
		if (temp.numero_ingredienti > MAX_INGREDIENTI) {
			temp.numero_ingredienti = MAX_INGREDIENTI;
		}

		int count = 0;
		char *ing_tok = strtok(ingredienti, ";");
		while (ing_tok != NULL && count < temp.numero_ingredienti) {
			char ing_nome[MAX_LEN_ING_NAME];
			double ing_dose;
			if (sscanf(ing_tok, " %99[^:]: %lf", ing_nome, &ing_dose) == 2) {
				strcpy(temp.ingredienti[count].nome, ing_nome);
				temp.ingredienti[count].dose = ing_dose;
				count++;
			}
			ing_tok = strtok(NULL, ";");
		}
		temp.numero_ingredienti = count;

		ricettario->pietanze[index] = temp;
		index++;
	}

	ricettario->numero_pietanze = index;		// aggiorno il numero di pietanze inserite da file
}
