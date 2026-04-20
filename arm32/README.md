# Esercizi Assembly ARM 32

Svolgimento degli esercizi proposti nel corso di Architetture dei Calcolatori (A.A. 25/26). Per ogni esercitazione proposta c'è una macroarea assegnata con corrispettiva cartella contenente gli esercizi svolti. Per ogni esercizio si propongono due soluzioni.

## Convenzioni

- **Data:** formato `aaaa-mm-dd` (es. `2026-01-31`)
- **Numerazione:** riparte da `01` per ogni macroarea
- **Titolo esercizio:** `Macroarea - NN (aaaa-mm-dd) - Titolo`

## Elenco Esercizi

### Array e Sostituzione - 01 (2026-01-31) - CheckBit

- Link soluzioni: [soluzione1](./ArrayESostituzione/CheckBit_2026-01-31/soluzione1.s), [soluzione2](./ArrayESostituzione/CheckBit_2026-01-31/soluzione2.s)
- Descrizione: Conta gli elementi di un array con bit 7 non settato e li sostituisce con un contatore progressivo.

### Array e Sostituzione - 02 (2026-01-10) - CountAndSubstitute

- Link soluzioni: [soluzione1](./ArrayESostituzione/CountAndSubstitute_2026-01-10/soluzione1.s), [soluzione2](./ArrayESostituzione/CountAndSubstitute_2026-01-10/soluzione2.s)
- Descrizione: Conta i valori negativi in un array e li sostituisce con un valore dato.

### Array e Sostituzione - 03 (2025-12-19) - Div4Array

- Link soluzioni: [soluzione1](./ArrayESostituzione/Div4Array_2025-12-19/soluzione1.s), [soluzione2](./ArrayESostituzione/Div4Array_2025-12-19/soluzione2.s)
- Descrizione: Divide per 4 tutti gli elementi di un array usando shift logico a destra.

### Operazioni Aritmetiche - 01 (2025-12-19) - MinTwoIntegers

- Link soluzioni: [soluzione1](./OperazioniAritmetiche/MinTwoIntegers_2025-12-19/soluzione1.s)
- Descrizione: Restituisce il minimo tra due interi con segno a 32 bit.

### Operazioni Aritmetiche - 02 (2026-01-13) - Mul5

- Link soluzioni: [soluzione1](./OperazioniAritmetiche/Mul5_2026-01-13/soluzione1.s)
- Descrizione: Moltiplica un intero per 5 con shift e addizione (`x * 5 = x * 4 + x`).

### Operazioni Aritmetiche - 03 (2025-12-19) - NegateSubroutine

- Link soluzioni: [soluzione1](./OperazioniAritmetiche/NegateSubroutine_2025-12-19/soluzione1.s)
- Descrizione: Cambia il segno di un intero usando reverse subtract (RSB).

### Array e Sostituzione - 04 (2025-12-19) - OddArrayCounter

- Link soluzioni: [soluzione1](./ArrayESostituzione/OddArrayCounter_2025-12-19/soluzione1.s), [soluzione2](./ArrayESostituzione/OddArrayCounter_2025-12-19/soluzione2.s)
- Descrizione: Conta e sostituisce i valori dispari di un array con i loro indici.

### Array e Sostituzione - 05 (2026-01-31) - SubReg

- Link soluzioni: [soluzione1](./ArrayESostituzione/SubReg_2026-01-31/soluzione1.s), [soluzione2](./ArrayESostituzione/SubReg_2026-01-31/soluzione2.s)
- Descrizione: Sottrae un valore da ogni elemento di un array e conta quanti diventano negativi.

### Array e Sostituzione - 06 (2026-02-15) - CheckAndSubstitute

- Link soluzioni: [soluzione1](./ArrayESostituzione/CheckAndSubstitute_2026-02-15/soluzione1.s), [soluzione2](./ArrayESostituzione/CheckAndSubstitute_2026-02-15/soluzione2.s)
- Descrizione: Scorre un array e conta quanti elementi soddisfano la condizione della consegna, sovrascrivendoli con l'indice corrente.

---

## Esecuzione e Debug con arm.sh

Script disponibile: [arm.sh](./arm.sh)

Funzione dello script:

- assembla il file `.s`
- effettua il linking
- avvia il binario su `qemu-arm` con GDB server (`-g 1122`)
- apre `gdb-multiarch` gia' collegato

Uso rapido da cartella `arm32`:

```bash
./arm.sh ArrayESostituzione/CheckBit_2026-01-31/soluzione1.s
```

Comandi utili in GDB (help dello script):

```bash
./arm.sh -h
```

Prerequisiti tipici:

- `arm-linux-gnueabihf-as`
- `arm-linux-gnueabihf-ld`
- `qemu-arm`
- `gdb-multiarch`

---

## Warning

> ⚠️ Attenzione
>
> - Le soluzioni presenti sono proposte didattiche: possono esistere implementazioni diverse ugualmente corrette.
> - Alcuni esercizi possono avere piu' interpretazioni in base alla consegna specifica del docente.
> - In base all'argomento svolto a lezione, le soluzioni privilegiano la chiarezza del flusso Assembly.

**Autore**: Ignazio Leonardo Calogero Sperandeo

by jimbug // :)