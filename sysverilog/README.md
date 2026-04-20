# Esercizi di Programmazione SysVerilog

Svolgimento degli esercizi proposti nel corso di Architetture dei Calcolatori (A.A. 25/26). Per ogni esercitazione proposta c'e' una macroarea assegnata con corrispettiva cartella contenente gli esercizi svolti. Per ogni esercizio si propone una possibile soluzione.

Per ogni esercizio sono presenti:

- `soluzione1.sv`: implementazione della rete/FSM
- `tb_soluzione1.sv`: testbench con clock, reset, stimoli e dump VCD

## Convenzioni

- **Data:** formato `aaaa-mm-dd` (es. `2026-02-09`)
- **Numerazione:** riparte da `01` per ogni macroarea
- **Titolo esercizio:** `Macroarea - NN (aaaa-mm-dd) - Titolo`

## Elenco Esercizi

### Finite State Machine Moore - 01 (2026-01-16) - Riconoscitore di Parita negli Ultimi 3 Bit

- **Link soluzione:** [Apri codice](./FiniteStateMachineMoore/Esercitazione_2026-01-16/soluzione1.sv)
- **Link testbench:** [Apri testbench](./FiniteStateMachineMoore/Esercitazione_2026-01-16/tb_soluzione1.sv)
- **Descrizione:** L'uscita vale `0` quando negli ultimi 3 bit compaiono esattamente due `1` (numero pari di `1`, escluso `000`), altrimenti vale `1`.

### Finite State Machine Moore - 02 (2025-12-19) - Uscita Trasparente Ritardata

- **Link soluzione:** [Apri codice](./FiniteStateMachineMoore/Esercitazione_2025-12-19/soluzione1.sv)
- **Link testbench:** [Apri testbench](./FiniteStateMachineMoore/Esercitazione_2025-12-19/tb_soluzione1.sv)
- **Descrizione:** L'uscita segue l'ingresso durante il ciclo corrente solo se al fronte di clock precedente l'ingresso era `1`; altrimenti resta `0`.

---

## Esami

Raccolta dei quesiti d'esame proposti durante il corso relativi a reti sequenziali in stile Moore.

### Esame - 01 (2025-02-05) - Rilevatore di Uguaglianza (Ultimi Due Bit Uguali)

- **Link soluzione:** [Apri codice](./Esami/Esame_2025-02-05/soluzione1.sv)
- **Link testbench:** [Apri testbench](./Esami/Esame_2025-02-05/tb_soluzione1.sv)
- **Descrizione:** L'uscita vale `1` quando gli ultimi due bit ricevuti in ingresso sono uguali, altrimenti vale `0`.

### Esame - 02 (2023-01-13, 2025-01-14) - Rilevatore di Sequenza "011"

- **Link soluzione:** [Apri codice](./Esami/Esame_2023-01-13/soluzione1.sv)
- **Link testbench:** [Apri testbench](./Esami/Esame_2023-01-13/tb_soluzione1.sv)
- **Descrizione:** L'uscita vale `0` quando negli ultimi bit ricevuti viene riconosciuta la sequenza `0,1,1`; per tutte le altre sequenze vale `1`.

### Esame - 03 (2023-02-19) - Rilevatore di Sequenza "010"

- **Link soluzione:** [Apri codice](./Esami/Esame_2023-02-19/soluzione1.sv)
- **Link testbench:** [Apri testbench](./Esami/Esame_2023-02-19/tb_soluzione1.sv)
- **Descrizione:** L'uscita vale `0` solo quando riconosce la sequenza `0,1,0` negli ultimi bit, altrimenti rimane a `1`.

### Esame - 04 (2026-02-09) - Conteggio dei Bit a 1 negli Ultimi 2 Valori

- **Link soluzione:** [Apri codice](./Esami/Esame_2026-02-09/soluzione1.sv)
- **Link testbench:** [Apri testbench](./Esami/Esame_2026-02-09/tb_soluzione1.sv)
- **Descrizione:** L'uscita su 2 bit riporta quanti bit a `1` sono presenti negli ultimi due valori d'ingresso.

### Esame - 05 (2026-02-23) - Contatore Limitato Bidirezionale 0-4

- **Link soluzione:** [Apri codice](./Esami/Esame_2026-02-23/soluzione1.sv)
- **Link testbench:** [Apri testbench](./Esami/Esame_2026-02-23/tb_soluzione1.sv)
- **Descrizione:** Il valore di uscita viene incrementato con `x=0` e decrementato con `x=1`, con saturazione tra `0` e `4`.

---

## Simulazione Rapida (Dockerfile)

Esecuzione consigliata usando il Dockerfile presente in questa cartella.

Prima volta (solo una volta):

	docker build -t sv-sim .

Poi, dalla cartella dell'esercizio (quella con `soluzione1.sv` e `tb_soluzione1.sv`):

	docker run --rm -v "$PWD":/work -w /work sv-sim

Se il testbench genera dump_moore.vcd, il file resta nella cartella dell'esercizio.

## Warning

> ⚠️ **Attenzione**
>
> - Le soluzioni presenti sono proposte didattiche: possono esistere implementazioni diverse ugualmente corrette.
> - Le FSM sono progettate mediante Moore.
> - Alcuni testbench assumono segnali di ingresso validi secondo la consegna; con stimoli fuori specifica il comportamento potrebbe non essere significativo.

**Autore:** Ignazio Leonardo Calogero Sperandeo

by jimbug // :)
