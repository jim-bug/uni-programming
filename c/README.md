# Esercizi di Programmazione C

Svolgimento degli esercizi proposti nel corso di Fondamenti di Programmazione (A.A. 25/26). Per ogni esercitazione proposta c'è una macroarea assegnata con corrispettiva cartella contenente gli esercizi svolti. Per ogni esercizio si propone una possibile soluzione.

## Convenzioni

- **Data:** formato `aaaa-mm-dd` (es. `2026-03-14`)
- **Numerazione:** riparte da `01` per ogni macroarea
- **Titolo esercizio:** `Macroarea - NN (aaaa-mm-dd) - Titolo`

## Elenco Esercizi

### Manipolazione Dati - 01 (2026-03-14) - Conversione Temperature

- **Link:** [Apri codice](./ManipolazioneDati_2026-03-13/esercizio1.c)
- **Descrizione:** Dato un valore in gradi Celsius, calcola e stampa (con due cifre decimali) i corrispondenti valori in Fahrenheit e Kelvin (`F = C * 9/5 + 32`, `K = C + 273.15`).

### Manipolazione Dati - 02 (2026-03-14) - Velocità Media

- **Link:** [Apri codice](./ManipolazioneDati_2026-03-13/esercizio2.c)
- **Descrizione:** Calcola la velocità media in km/h dati in input una distanza in chilometri (reale) e un tempo in ore e minuti (inseriti come interi distinti).

### Manipolazione Dati - 03 (2026-03-14) - Resto in Monete

- **Link:** [Apri codice](./ManipolazioneDati_2026-03-13/esercizio3.c)
- **Descrizione:** Dato un importo in centesimi, calcola il numero minimo di monete necessarie (da 50, 20, 10, 5, 2 e 1 centesimo) per ottenerlo.

### Manipolazione Dati - 04 (2026-03-14) - Estrazione Cifre

- **Link:** [Apri codice](./ManipolazioneDati_2026-03-13/esercizio4.c)
- **Descrizione:** Dato un numero intero a tre cifre (100-999), ne estrae e stampa separatamente le centinaia, le decine e le unità.

### Manipolazione Dati - 05 (2026-03-14) - Shift di Caratteri Cifrario

- **Link:** [Apri codice](./ManipolazioneDati_2026-03-13/esercizio5.c)
- **Descrizione:** Dato un carattere maiuscolo ('A'-'Z') e uno spostamento tra 1 e 25, avanza il carattere con avvolgimento circolare oltre la 'Z'.

---

### Costrutti Condizionali e Iterativi - 01 (2026-03-20) - Valore Assoluto, Calcolatrice, Scambio Variabili

- **Link:** [Apri codice](./CotruttiCondizionaliIterativi_2026-03-20/esercizio1.c)
- **Descrizione:** Tre sottoproblemi: (1) Calcolare il valore assoluto di un numero in input; (2) Permettere all'utente di inserire due numeri e un operatore (+, -, *, /) per stampare il risultato; (3) Scambiare il valore di due variabili intere.

### Costrutti Condizionali e Iterativi - 02 (2026-03-20) - Verifica Anno Bisestile

- **Link:** [Apri codice](./CotruttiCondizionaliIterativi_2026-03-20/esercizio2.c)
- **Descrizione:** Dato un anno in input, verificare se è bisestile. Un anno è bisestile se divisibile per 4 ma non per 100, oppure se divisibile per 400.

### Costrutti Condizionali e Iterativi - 03 (2026-03-20) - Ordinamento Tre Numeri

- **Link:** [Apri codice](./CotruttiCondizionaliIterativi_2026-03-20/esercizio3.c)
- **Descrizione:** Chiede all'utente di inserire tre numeri interi (n1, n2, n3) e li ordina in modo crescente, stampando i nuovi valori delle variabili.

### Costrutti Condizionali e Iterativi - 04 (2026-03-20) - Vocale o Consonante

- **Link base:** [Apri codice](./CotruttiCondizionaliIterativi_2026-03-20/esercizio4-1.c)
- **Link case-insensitive:** [Apri codice](./CotruttiCondizionaliIterativi_2026-03-20/esercizio4-2.c)
- **Descrizione:** Chiede all'utente di inserire un carattere minuscolo e determina se è una vocale o una consonante. La versione base accetta solo minuscole; la versione case-insensitive accetta sia maiuscole che minuscole.

### Costrutti Condizionali e Iterativi - 05 (2026-03-20) - Fattoriale

- **Link:** [Apri codice](./CotruttiCondizionaliIterativi_2026-03-20/esercizio5.c)
- **Descrizione:** Chiede all'utente di inserire un numero intero N e stampa il valore del fattoriale di N. Ricorda che 0! = 1 e il fattoriale è il prodotto di tutti i numeri compresi tra 1 e N.

### Costrutti Condizionali e Iterativi - 06 (2026-03-20) - Serie di Fibonacci

- **Link:** [Apri codice](./CotruttiCondizionaliIterativi_2026-03-20/esercizio6.c)
- **Descrizione:** Stampa i primi N numeri di Fibonacci, con N definito dall'utente. La sequenza inizia con 1 e 1, e ogni successivo valore è la somma dei due precedenti (1 1 2 3 5 8 13 21 34 55...).

---

### Array Monodimensionali - 01 (2026-03-27) - Ricerca di un Valore

- **Link:** [Apri codice](./ArrayMonodimensionali_2026-03-27/esercizio1.c)
- **Descrizione:** Consente di inserire una sequenza di numeri interi positivi in un array di dimensione N e permette di verificare se un valore richiesto è presente nella sequenza.

### Array Monodimensionali - 02 (2026-03-27) - Shift a Sinistra

- **Link base:** [Apri codice](./ArrayMonodimensionali_2026-03-27/esercizio2.c)
- **Link variante con k:** [Apri codice](./ArrayMonodimensionali_2026-03-27/esercizio2-1.c)
- **Descrizione:** Inserisce N numeri interi in un array e sposta tutti gli elementi di una posizione a sinistra. La variante extra permette di specificare quante posizioni k spostare a sinistra.

### Array Monodimensionali - 03 (2026-03-30) - Verifica Palindromo a 5 Cifre

- **Link:** [Apri codice](./ArrayMonodimensionali_2026-03-27/esercizio3.c)
- **Descrizione:** Verifica se un numero intero a 5 cifre inserito dall'utente è palindromo, separando le cifre tramite divisione intera e operatore modulo.

### Array Monodimensionali - 04 (2026-03-30) - Ricerca di Pattern in Sequenza

- **Link:** [Apri codice](./ArrayMonodimensionali_2026-03-27/esercizio4.c)
- **Descrizione:** Cerca un pattern di interi senza salti all'interno di una sequenza più lunga e restituisce l'indice di inizio (base 0) della prima occorrenza, oppure -1 se assente.

### Array Monodimensionali - 05 (2026-03-30) - Numeri Primi con Setaccio di Eratostene

- **Link:** [Apri codice](./ArrayMonodimensionali_2026-03-27/esercizio5.c)
- **Descrizione:** Usa un array di 1000 elementi per trovare e stampare tutti i numeri primi tra 2 e 999 applicando il metodo del Setaccio di Eratostene.

---

## Esami

Raccolta delle prove d'esame e prove in itinere proposte durante il corso di Fondamenti di Programmazione (A.A. 25/26). Sono presenti anche svolgimenti di esami passati.

### Itinere - 01 (2025-04-15) - Conteggio di Coppie con Somma Specifica

- **Link:** [Apri codice](./Esami_2026-04-01/Itinere_2025-04-15/esercizio1.c)
- **Descrizione:** Chiede all'utente di inserire una sequenza di N numeri interi e un valore di somma target S. Conta e stampa il numero di coppie distinte tali la loro somma faccia S, considerando solo coppie distinte dal punto di vista degli indici.

## Warning

> ⚠️ **Attenzione**
>
> - Le soluzioni presenti sono proposte didattiche: possono esistere implementazioni diverse ugualmente corrette.
> - Alcuni programmi assumono input validi secondo la consegna; con input fuori specifica il comportamento potrebbe non essere significativo.
> - In base alla macroarea dell'esercizio la soluzione è designata sugli argomenti svolti fino a quel punto nel corso.
>

**Autore:** Ignazio Leonardo Calogero Sperandeo

by jimbug // :)
