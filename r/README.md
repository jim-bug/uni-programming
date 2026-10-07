# Esercizi di Statistica

Svolgimento degli esercizi proposti nel corso di Statistica (A.A. 26/27). Per ogni esercitazione proposta c'è una macroarea assegnata con corrispettiva cartella contenente gli esercizi svolti. Per ogni esercizio si propone una possibile soluzione.

## Convenzioni

- **Data:** formato `aaaa-mm-dd` (es. `2026-03-14`)
- **Numerazione:** riparte da `01` per ogni macroarea
- **Titolo esercizio:** `Macroarea - NN (aaaa-mm-dd) - Titolo`

## Elenco Esercizi

### Esercizio di riepilogo - 01 (2026-09-22) - Vettori, Matrici e Dataframe

- **Link:** [Apri codice](./2026-09-22-VettoriMatriciDataframe/esercizio1.r)
- **Descrizione:** Costruisce la sequenza numerica `s1` da 1 a 100 con passo 5 e ne determina la lunghezza. Costruisce il vettore non numerico `s2`, formato da 10 ripetizioni di `"M"` e 10 ripetizioni di `"F"`, utilizzando un'unica istruzione. Unisce i due vettori nella matrice `M1`, verifica che l'oggetto sia una matrice, assegna alle colonne i nomi `eta` e `sesso`, crea il dataframe `M1.df` e seleziona le osservazioni con `eta <= 50`.

### Esercizio di riepilogo - 02 (2026-09-29) - Importazione dati, gestione variabili e fattori ordinali

- **Link:** [Apri codice](./2026-09-29-ImportazioneVariabili/esercizio1.r)
- **Descrizione:** Importa il file di testo `DatiStat1.txt`, controlla la natura e la struttura delle variabili, estrae `Altezza` nel vettore `alt`, converte il grado di istruzione dei genitori in fattori ordinali, seleziona gli studenti diplomati presso il liceo scientifico, individua gli indici degli studenti con altezza inferiore a 168 cm e filtra quelli i cui genitori possiedono entrambi la laurea.

### Esercizio di riepilogo - 03 (2026-10-06) - Medie, percentili, variabilità ed eterogeneità

- **Link:** [Apri codice](./2026-10-06-MedieVariabilita/esercizio1.R)
- **Descrizione:**
	- **Parte 1 - Importazione e analisi descrittiva di base**
		- **Punto 1:** importare il dataset `Cpus_data.csv` e calcolare la media e la mediana della variabile `Recommended_Customer_Price`, gestendo gli eventuali valori mancanti. Rappresentare la distribuzione dei prezzi con un istogramma, specificando titolo, nomi degli assi e colore del grafico.
	- **Parte 2 - Percentili, categorizzazione in classi e cumulate**
		- **Punto 2:** calcolare i percentili 0, 10, 22, 40, 75, 99 e 100 di `Recommended_Customer_Price`. Utilizzare i percentili come estremi delle classi e costruire una tabella contenente frequenze assolute, frequenze relative, frequenze assolute cumulate e frequenze relative cumulate.
	- **Parte 3 - Confronti sulle medie e rappresentazioni grafiche**
		- **Punto 3:** confrontare la media calcolata sulla distribuzione originale con la media della distribuzione in classi. Per quest'ultima, utilizzare i punti medi delle classi e ponderarli con le frequenze assolute.
		- **Punto 4:** rappresentare la distribuzione di `Recommended_Customer_Price` con un boxplot condizionato alla variabile categorica `Product_Collection`, così da confrontare i prezzi nelle diverse collezioni di prodotto.
	- **Parte 4 - Variabilità ed eterogeneità (punti integrativi)**
		- **Punto 5:** calcolare la varianza campionaria di `Max_Memory_Size` e `Max_Memory_Bandwidth`. Confrontare la variabilità relativa delle due variabili tramite il coefficiente di variazione, espresso in percentuale.
		- **Punto 6:** analizzare l'eterogeneità della variabile qualitativa `Cache_Type` mediante le frequenze relative e l'indice di Gini assoluto. Calcolare inoltre il valore massimo teorico dell'indice, dato da $(m - 1) / m$, e l'indice di Gini normalizzato.



## Warning

> ⚠️ **Attenzione**
>
> - Le soluzioni presenti sono proposte didattiche: possono esistere implementazioni diverse ugualmente corrette.
> - Alcuni programmi assumono input validi secondo la consegna; con input fuori specifica il comportamento potrebbe non essere significativo.
> - In base alla macroarea dell'esercizio la soluzione è designata sugli argomenti svolti fino a quel punto nel corso.
>
**Autore:** Ignazio Leonardo Calogero Sperandeo

by jimbug // :)
