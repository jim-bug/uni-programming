/*
*	Autore: Ignazio Leonardo Calogero Sperandeo
*	Data: 2026-05-22
*	Consegna: Rif. README.md
*	by jimbug // :)
*/

#include <stdio.h>
#include <string.h>


#define MAX_INGREDIENTI 10
#define MAX_PIETANZE 100
#define LEN_TIPI 5

const char* TIPI[LEN_TIPI] = {"Antipasto", "Primo", "Secondo", "Contorno", "Dolce"};

typedef struct Ingrediente {
	char nome[100];
	double dose;
} Ingrediente;

typedef struct Pietanza {
	char nome[100];
	Ingrediente ingredienti[MAX_INGREDIENTI];
	double tempo;
	int numero_ingredienti;
	char tipo[100];
} Pietanza;

typedef struct Ricettario {
	Pietanza pietanze[MAX_PIETANZE];
	int numero_pietanze;
} Ricettario;

void print_menu();
void insert(Ricettario*, int);
void view_by_pietanza(Ricettario*, char[]);
void view_by_type(Ricettario*, char[]);
void view_by_ingrediente(Ricettario*, Ingrediente);
void view_by_time(Ricettario*, double);

int main(void) {
	Ricettario ricettario;
	int opzione, last = 0;

	printf("Inserisci il numero di pietanze da inserire: ");
	scanf("%d", &ricettario.numero_pietanze);

	do {
		print_menu();
		printf("Opzione scelta: ");
		scanf("%d", &opzione);

		switch(opzione){
			case 1:
				insert(&ricettario, last);
				last ++;

				break;
			case 2:{
				char nome[100];
				printf("Inserisci il nome della pietanza da ricercare: ");
					scanf(" %99[^\n]", nome);
				view_by_pietanza(&ricettario, nome);

				break;
			}
			case 3: {
				char tipo[100];
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
				break;
			default:
				printf("Opzione non valida!\n");
				break;
		}
	} while(opzione != 6);


	return 0;
	

}

void print_menu(){
	printf("\t\t\t\tBENVENUTO NEL MENU\n");
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

void insert(Ricettario* ricettario, int i){
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
}

void view_by_pietanza(Ricettario* ricettario, char nome[]){
	for (int i = 0; i < ricettario->numero_pietanze; i++){
		if (!strcmp(ricettario->pietanze[i].nome, nome)){
			printf("Ingredienti di: %s:", ricettario->pietanze[i].nome);
			for (int j = 0; j < ricettario->pietanze[i].numero_ingredienti; j ++)
				printf("\t%d) Ingrediente: %s | Dose: %lf g\n", j + 1, ricettario->pietanze[i].ingredienti[j].nome, ricettario->pietanze[i].ingredienti[j].dose);
			break;
		}
	}
}

void view_by_type(Ricettario* ricettario, char tipo[]){
	printf("Elenco dei %s:\n", tipo);
	for (int i = 0; i < ricettario->numero_pietanze; i++){
		if (!strcmp(ricettario->pietanze[i].tipo, tipo)){
			printf("\t%d) Nome Pietanza: %s\n", i + 1, ricettario->pietanze[i].nome);
		}
	}
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
	for (int i = 0; i < ricettario->numero_pietanze; i++){
		if(ricettario->pietanze[i].tempo < time){
			printf("\t%d) Nome Pietanza: %s\n", i + 1, ricettario->pietanze[i].nome);
		}
	}
}
