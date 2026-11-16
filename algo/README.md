# Esercizi di Algoritmi e Strutture Dati

Svolgimento degli esercizi proposti nel corso di Algoritmi e Strutture Dati (A.A. 26/27). Per ogni esercitazione proposta c'è una macroarea assegnata con corrispettiva cartella contenente gli esercizi svolti. Per ogni esercizio si propone una possibile soluzione.

## Convenzioni

- **Data:** formato `aaaa-mm-dd` (es. `2026-03-14`)
- **Numerazione:** riparte da `01` per ogni macroarea
- **Titolo esercizio:** `Macroarea - NN (aaaa-mm-dd) - Titolo`

## Elenco Esercizi

### Algoritmi di Ricerca - 01 (2026-10-04) - Ricerca Sequenziale

- **Link:** [Apri codice](./2026-10-04-AlgoritmiRicerca/esercizio1.c)
- **Descrizione:** Implementa una funzione di ricerca sequenziale che scorre un array di interi e restituisce l'indice della prima occorrenza del valore cercato, oppure `-1` se il valore non e presente.

### Algoritmi di Ricerca - 02 (2026-10-04) - Ricerca Binaria Iterativa

- **Link:** [Apri codice](./2026-10-04-AlgoritmiRicerca/esercizio2.c)
- **Link extra:** [Apri codice](./2026-10-04-AlgoritmiRicerca/esercizio3.c)
- **Descrizione:** Implementa una funzione di ricerca binaria iterativa sull'array ordinato `{2, 5, 8, 12, 16, 23, 38, 56, 72, 91}`. A ogni iterazione stampa il numero del passo e i valori di `low`, `high` e `mid`, provando la ricerca con `x = 23` e `x = 20`. Come extra, implementa anche una funzione di ricerca binaria ricorsiva in C.

## Librerie di strutture dati

### Dizionario

- **Link:** [Apri libreria](./lib/strutture/dict/)
- **Consegna:** Implementazione di un dizionario (ADT) mediante lista concatenata, con associazioni stringa-intero.
- **Utilizzo:** un dizionario vuoto è rappresentato da `Dict* dict = NULL`; `dict_insert` restituisce un `DictStatus` e aggiorna la testa tramite `Dict**`.
- **Gestione memoria:** usare `dict_destroy` al termine dell'utilizzo.

### Pila

- **Link:** [Apri libreria](./lib/strutture/stack/)
- **Consegna:** Implementazione di una pila (ADT) di interi mediante lista concatenata.
- **Utilizzo:** una pila vuota è rappresentata da `Stack* stack = NULL`; `stack_push`, `stack_pop` e `stack_top` restituiscono uno `StackStatus`.
- **Gestione memoria:** usare `stack_destroy` al termine dell'utilizzo.

## Warning

> ⚠️ **Attenzione**
>
> - Le soluzioni presenti sono proposte didattiche: possono esistere implementazioni diverse ugualmente corrette.
> - Alcuni programmi assumono input validi secondo la consegna; con input fuori specifica il comportamento potrebbe non essere significativo.
> - In base alla macroarea dell'esercizio la soluzione è designata sugli argomenti svolti fino a quel punto nel corso.
> - Le librerie non terminano direttamente il programma in caso di errore: restituiscono stati espliciti, lasciando al chiamante la gestione di valori nulli, pila vuota, chiavi assenti e fallimenti di allocazione.
> 
**Autore:** Ignazio Leonardo Calogero Sperandeo

by jimbug // :)
