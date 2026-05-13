# Esercizi di Programmazione C

Svolgimento degli esercizi proposti nel corso di Fondamenti di Programmazione (A.A. 25/26). Per ogni esercitazione proposta c'è una macroarea assegnata con corrispettiva cartella contenente gli esercizi svolti. Per ogni esercizio si propone una possibile soluzione.

## Convenzioni

- **Data:** formato `aaaa-mm-dd` (es. `2026-03-14`)
- **Numerazione:** riparte da `01` per ogni macroarea
- **Titolo esercizio:** `Macroarea - NN (aaaa-mm-dd) - Titolo`

## Elenco Esercizi

### Manipolazione Dati - 01 (2026-03-14) - Conversione Temperature

- **Link:** [Apri codice](./2026-03-13_ManipolazioneDati/esercizio1.c)
- **Descrizione:** Dato un valore in gradi Celsius, calcola e stampa (con due cifre decimali) i corrispondenti valori in Fahrenheit e Kelvin (`F = C * 9/5 + 32`, `K = C + 273.15`).

### Manipolazione Dati - 02 (2026-03-14) - Velocità Media

- **Link:** [Apri codice](./2026-03-13_ManipolazioneDati/esercizio2.c)
- **Descrizione:** Calcola la velocità media in km/h dati in input una distanza in chilometri (reale) e un tempo in ore e minuti (inseriti come interi distinti).

### Manipolazione Dati - 03 (2026-03-14) - Resto in Monete

- **Link:** [Apri codice](./2026-03-13_ManipolazioneDati/esercizio3.c)
- **Descrizione:** Dato un importo in centesimi, calcola il numero minimo di monete necessarie (da 50, 20, 10, 5, 2 e 1 centesimo) per ottenerlo.

### Manipolazione Dati - 04 (2026-03-14) - Estrazione Cifre

- **Link:** [Apri codice](./2026-03-13_ManipolazioneDati/esercizio4.c)
- **Descrizione:** Dato un numero intero a tre cifre (100-999), ne estrae e stampa separatamente le centinaia, le decine e le unità.

### Manipolazione Dati - 05 (2026-03-14) - Shift di Caratteri Cifrario

- **Link:** [Apri codice](./2026-03-13_ManipolazioneDati/esercizio5.c)
- **Descrizione:** Dato un carattere maiuscolo ('A'-'Z') e uno spostamento tra 1 e 25, avanza il carattere con avvolgimento circolare oltre la 'Z'.

---

### Costrutti Condizionali e Iterativi - 01 (2026-03-20) - Valore Assoluto, Calcolatrice, Scambio Variabili

- **Link:** [Apri codice](./2026-03-20_CotruttiCondizionaliIterativi/esercizio1.c)
- **Descrizione:** Tre sottoproblemi: (1) Calcolare il valore assoluto di un numero in input; (2) Permettere all'utente di inserire due numeri e un operatore (+, -, *, /) per stampare il risultato; (3) Scambiare il valore di due variabili intere.

### Costrutti Condizionali e Iterativi - 02 (2026-03-20) - Verifica Anno Bisestile

- **Link:** [Apri codice](./2026-03-20_CotruttiCondizionaliIterativi/esercizio2.c)
- **Descrizione:** Dato un anno in input, verificare se è bisestile. Un anno è bisestile se divisibile per 4 ma non per 100, oppure se divisibile per 400.

### Costrutti Condizionali e Iterativi - 03 (2026-03-20) - Ordinamento Tre Numeri

- **Link:** [Apri codice](./2026-03-20_CotruttiCondizionaliIterativi/esercizio3.c)
- **Descrizione:** Chiede all'utente di inserire tre numeri interi (n1, n2, n3) e li ordina in modo crescente, stampando i nuovi valori delle variabili.

### Costrutti Condizionali e Iterativi - 04 (2026-03-20) - Vocale o Consonante

- **Link base:** [Apri codice](./2026-03-20_CotruttiCondizionaliIterativi/esercizio4-1.c)
- **Link case-insensitive:** [Apri codice](./2026-03-20_CotruttiCondizionaliIterativi/esercizio4-2.c)
- **Descrizione:** Chiede all'utente di inserire un carattere minuscolo e determina se è una vocale o una consonante. La versione base accetta solo minuscole; la versione case-insensitive accetta sia maiuscole che minuscole.

### Costrutti Condizionali e Iterativi - 05 (2026-03-20) - Fattoriale

- **Link:** [Apri codice](./2026-03-20_CotruttiCondizionaliIterativi/esercizio5.c)
- **Descrizione:** Chiede all'utente di inserire un numero intero N e stampa il valore del fattoriale di N. Ricorda che 0! = 1 e il fattoriale è il prodotto di tutti i numeri compresi tra 1 e N.

### Costrutti Condizionali e Iterativi - 06 (2026-03-20) - Serie di Fibonacci

- **Link:** [Apri codice](./2026-03-20_CotruttiCondizionaliIterativi/esercizio6.c)
- **Descrizione:** Stampa i primi N numeri di Fibonacci, con N definito dall'utente. La sequenza inizia con 1 e 1, e ogni successivo valore è la somma dei due precedenti (1 1 2 3 5 8 13 21 34 55...).

---

### Array Monodimensionali - 01 (2026-03-27) - Ricerca di un Valore

- **Link:** [Apri codice](./2026-03-27_ArrayMonodimensionali/esercizio1.c)
- **Descrizione:** Consente di inserire una sequenza di numeri interi positivi in un array di dimensione N e permette di verificare se un valore richiesto è presente nella sequenza.

### Array Monodimensionali - 02 (2026-03-27) - Shift a Sinistra

- **Link base:** [Apri codice](./2026-03-27_ArrayMonodimensionali/esercizio2.c)
- **Link variante con k:** [Apri codice](./2026-03-27_ArrayMonodimensionali/esercizio2-1.c)
- **Descrizione:** Inserisce N numeri interi in un array e sposta tutti gli elementi di una posizione a sinistra. La variante extra permette di specificare quante posizioni k spostare a sinistra.

### Array Monodimensionali - 03 (2026-03-30) - Verifica Palindromo a 5 Cifre

- **Link:** [Apri codice](./2026-03-27_ArrayMonodimensionali/esercizio3.c)
- **Descrizione:** Verifica se un numero intero a 5 cifre inserito dall'utente è palindromo, separando le cifre tramite divisione intera e operatore modulo.

### Array Monodimensionali - 04 (2026-03-30) - Ricerca di Pattern in Sequenza

- **Link:** [Apri codice](./2026-03-27_ArrayMonodimensionali/esercizio4.c)
- **Descrizione:** Cerca un pattern di interi senza salti all'interno di una sequenza più lunga e restituisce l'indice di inizio (base 0) della prima occorrenza, oppure -1 se assente.

### Array Monodimensionali - 05 (2026-03-30) - Numeri Primi con Setaccio di Eratostene

- **Link:** [Apri codice](./2026-03-27_ArrayMonodimensionali/esercizio5.c)
- **Descrizione:** Usa un array di 1000 elementi per trovare e stampare tutti i numeri primi tra 2 e 999 applicando il metodo del Setaccio di Eratostene.

---

### Matrici - 01 (2026-04-24) - Confronto tra Due Matrici

- **Link:** [Apri codice](./2026-04-24_Matrici/esercizio1.c)
- **Descrizione:** Date due matrici di interi di dimensione N×M inizializzate in-line, verifica se sono uguali oppure no e stampa a schermo l'esito del confronto.

### Matrici - 02 (2026-04-24) - Conteggio e Presenza di un Valore

- **Link:** [Apri codice](./2026-04-24_Matrici/esercizio2.c)
- **Descrizione:** Data una matrice di interi N×M e un valore intero k letti da tastiera, conta quante volte k compare nella matrice tramite una funzione. Aggiunge inoltre una funzione booleana che indica se k e presente almeno una volta, riutilizzando il conteggio.

### Matrici - 03 (2026-04-24) - Scambio tra Diagonali

- **Link:** [Apri codice](./2026-04-24_Matrici/esercizio3.c)
- **Descrizione:** Chiede all'utente il numero di righe n (n > 0) di una matrice quadrata di interi, ne acquisisce i valori e scambia tra loro gli elementi della diagonale principale e della diagonale secondaria.

### Matrici - 04 (2026-04-24) - Verifica Vittoria al Tris

- **Link:** [Apri codice](./2026-04-24_Matrici/esercizio4.c)
- **Descrizione:** Implementa una funzione che, data una griglia 3×3 di Tris e un giocatore ('X' o 'O'), restituisce un booleano che indica se il giocatore ha vinto. Il programma legge la griglia da tastiera e determina l'esito della partita.

### Matrici - 05 (2026-04-24) - Matrice a Spirale Oraria

- **Link:** [Apri codice](./2026-04-24_Matrici/esercizio5.c)
- **Descrizione:** Dato un intero positivo n, genera una matrice quadrata n×n contenente i numeri da 1 a n^2 disposti in ordine crescente a spirale in senso orario, con riempimento a partire dalla cella in alto a sinistra.

---

### Stringhe - 01 (2026-04-27) - Copia, Concatenazione e Confronto di Stringhe

- **Link senza string.h:** [Apri codice](./2026-04-27_Stringhe/esercizio1-1.c)
- **Link con string.h:** [Apri codice](./2026-04-27_Stringhe/esercizio1-2.c)
- **Descrizione:** Implementa, in due versioni, le funzioni per copiare una stringa in un'altra, concatenare due stringhe e confrontarle in ordine alfabetico. La prima versione usa funzioni definite manualmente, la seconda utilizza le funzioni di `string.h`.

### Stringhe - 02 (2026-04-27) - Conteggio di Caratteri in una Stringa

- **Link:** [Apri codice](./2026-04-27_Stringhe/esercizio2.c)
- **Descrizione:** Chiede all'utente di inserire una stringa di dimensione massima 100 e conta il numero di lettere maiuscole, lettere minuscole, cifre e altri caratteri presenti.

### Stringhe - 03 (2026-04-29) - Palindromi

- **Link:** [Apri codice](./2026-04-27_Stringhe/esercizio3.c)
- **Descrizione:** Scrive una funzione che riceve una stringa e restituisce 1 se è palindroma, 0 altrimenti, ignorando gli spazi ma mantenendo il confronto case-sensitive. Il programma legge una stringa di lunghezza massima 100 caratteri e ne verifica la natura palindroma.

### Stringhe - 04 (2026-04-29) - Validazione Password

- **Link:** [Apri codice](./2026-04-27_Stringhe/esercizio4.c)
- **Descrizione:** Implementa la funzione `valida_password` che controlla lunghezza minima di 8 caratteri, presenza di almeno una maiuscola, una minuscola, una cifra e un carattere speciale tra `! @ # $ % ^ & *`. Il programma legge una stringa di lunghezza massima 50 caratteri e stampa se la password è valida.

### Stringhe - 05 (2026-04-29) - Tombola

- **Link base:** [Apri codice](./2026-04-27_Stringhe/esercizio5-1.c)
- **Link ottimizzato:** [Apri codice](./2026-04-27_Stringhe/esercizio5-2.c)
- **Descrizione:** Definisce una funzione `tombola` che genera una sequenza casuale senza ripetizioni e conta quante volte viene chiamata `rand`. La versione ottimizzata riduce al minimo le chiamate a `rand` ed è pensata per test anche con quantità di numeri molto superiori, ad esempio 50.000.

### Stringhe - 06 (2026-04-29) - Generazione Password Casuale

- **Link base:** [Apri codice](./2026-04-27_Stringhe/esercizio6-1.c)
- **Link con validazione:** [Apri codice](./2026-04-27_Stringhe/esercizio6-2.c)
- **Descrizione:** Genera una password casuale di lunghezza scelta dall'utente tra 8 e 50 caratteri, usando maiuscole, minuscole, cifre e i caratteri speciali dell'esercizio precedente. La versione con validazione garantisce anche che la password superi il controllo della funzione `valida_password`.

### Stringhe - 07 (2026-04-29) - Anagrammi

- **Link:** [Apri codice](./2026-04-27_Stringhe/esercizio7.c)
- **Descrizione:** Verifica se due stringhe inserite dall'utente sono anagrammi, considerando solo lettere minuscole e ignorando gli spazi nel confronto.

---

### Puntatori - 01 (2026-05-06) - Min e Max di una Matrice

- **Link:** [Apri codice](./2026-05-06_Puntatori/esercizio1.c)
- **Descrizione:** Definisce la funzione `min_max` che "restituisce" tramite puntatori il valore minimo e il valore massimo contenuti in una matrice di interi di dimensione rows×cols, simulando la restituzione di due valori.

### Puntatori - 02 (2026-05-06) - Ricerca Carattere in Stringa

- **Link:** [Apri codice](./2026-05-06_Puntatori/esercizio2.c)
- **Descrizione:** Definisce la funzione `find_char` che cerca un carattere in una stringa e restituisce un puntatore alla prima occorrenza trovata, oppure `NULL` se assente. Il main verifica che modificare il valore tramite il puntatore modifichi anche la stringa originale.

### Puntatori - 03 (2026-05-06) - Conversione Stringa in Intero

- **Link:** [Apri codice](./2026-05-06_Puntatori/esercizio3.c)
- **Descrizione:** Definisce la funzione `my_atoi` che converte una stringa di cifre (es. `"12345"`) nel corrispondente valore intero in base 10 (es. `12345`).

### Puntatori - 04 (2026-05-06) - Conteggio Valori Positivi

- **Link:** [Apri codice](./2026-05-06_Puntatori/esercizio4.c)
- **Descrizione:** Definisce la funzione `conta_positivi` che conta quanti elementi di un array di interi sono maggiori di zero, utilizzando esclusivamente l'aritmetica dei puntatori senza notazione con indici.

### Puntatori - 05 (2026-05-06) - Tokenizzazione di una Stringa

- **Link:** [Apri codice](./2026-05-06_Puntatori/esercizio5.c)
- **Descrizione:** Definisce la funzione `my_strtok` che divide una stringa in token in base a un carattere separatore, memorizza i token in un array di stringhe (massimo 10 token da 20 caratteri ciascuno) e restituisce il numero di token individuati.

---

### Ricorsione - 01 (2026-05-13) - Lunghezza di una Stringa

- **Link:** [Apri codice](./2026-05-13-Ricorsione/esercizio1.c)
- **Descrizione:** Definisce una funzione ricorsiva in C che restituisce la lunghezza di una stringa data.

### Ricorsione - 02 (2026-05-13) - Ricerca Lineare

- **Link:** [Apri codice](./2026-05-13-Ricorsione/esercizio2.c)
- **Descrizione:** Definisce una funzione ricorsiva `linear_search` per effettuare la ricerca lineare di un elemento all'interno di un array.

### Ricorsione - 03 (2026-05-13) - Ricerca Binaria

- **Link:** [Apri codice](./2026-05-13-Ricorsione/esercizio3.c)
- **Descrizione:** Definisce una funzione ricorsiva `binary_search` per la ricerca binaria di un elemento in un array. Il prototipo richiesto è `int binary_search(int key, int array[], int low, int high);`. La funzione gestisce due casi base per terminare la ricerca e due casi ricorsivi per proseguirla.

### Ricorsione - 04 (2026-05-13) - Somma dei Pari Maggiori di k

- **Link:** [Apri codice](./2026-05-13-Ricorsione/esercizio4.c)
- **Descrizione:** Definisce una funzione ricorsiva in C che, ricevendo in input due numeri interi n e k, calcola la somma dei primi n numeri pari che siano maggiori di k.

### Ricorsione - 05 (2026-05-13) - Massimo in Array di Float

- **Link:** [Apri codice](./2026-05-13-Ricorsione/esercizio5.c)
- **Descrizione:** Definisce una funzione ricorsiva in C che restituisce il valore massimo contenuto in un array di float.

---

## Esami

Raccolta delle prove d'esame e prove in itinere proposte durante il corso di Fondamenti di Programmazione (A.A. 25/26). Sono presenti anche svolgimenti di esami passati.

### Itinere - 01 (2025-04-15) - Conteggio di Coppie con Somma Specifica

- **Link:** [Apri codice](./Esami/2025-04-15_Itinere/esercizio1.c)
- **Descrizione:** Chiede all'utente di inserire una sequenza di N numeri interi e un valore di somma target S. Conta e stampa il numero di coppie distinte tali la loro somma faccia S, considerando solo coppie distinte dal punto di vista degli indici.

### Itinere - 02 (2026-04-13) - Secondo Massimo di Sequenza Distinta

- **Link:** [Apri codice](./Esami/2026-04-13_Itinere/esercizio1.c)
- **Descrizione:** Chiede all'utente di inserire una sequenza di N numeri interi distinti (N ≥ 2) e identifica il secondo massimo della sequenza.

## Warning

> ⚠️ **Attenzione**
>
> - Le soluzioni presenti sono proposte didattiche: possono esistere implementazioni diverse ugualmente corrette.
> - Alcuni programmi assumono input validi secondo la consegna; con input fuori specifica il comportamento potrebbe non essere significativo.
> - In base alla macroarea dell'esercizio la soluzione è designata sugli argomenti svolti fino a quel punto nel corso.
>

**Autore:** Ignazio Leonardo Calogero Sperandeo

by jimbug // :)
