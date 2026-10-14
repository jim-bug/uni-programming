# Esercizi di Internet of Things

Svolgimento degli esercizi proposti nel corso di Internet of Things (A.A. 26/27). Per ogni esercitazione proposta c'è una macroarea assegnata con corrispettiva cartella contenente gli esercizi svolti. Per ogni esercizio si propone una possibile soluzione.

## Convenzioni

- **Data:** formato `aaaa-mm-dd` (es. `2026-03-14`)
- **Numerazione:** riparte da `01` per ogni macroarea
- **Titolo esercizio:** `Macroarea - NN (aaaa-mm-dd) - Titolo`

## Elenco Esercizi

### Diodi Led e Resistori - 01 (2026-10-07) - Accensione e spegnimento di due diodi led

- Consegna: mediante Arduino, controllare lo stato di due diodi LED attraverso un pulsante (switch). Premendo il pulsante, i LED devono mantenere il nuovo stato fino alla pressione successiva.
- Link soluzioni: [soluzione 1](./2026-10-07-LedResistori/esercizio1.ino), [soluzione 2 con if](./2026-10-07-LedResistori/esercizio1-2.ino)
- Link simulazione: [simulazione Arduino](https://www.tinkercad.com/things/3gGIPztGoAJ-2026-10-07-esercitazioneled?sharecode=-R7G134_52dGyjFTaGu7W92uJ1Y2h_f1ZVy1VVZ-be8)
- Link relazione tecnica: [relazione tecnica e circuito](./2026-10-07-LedResistori/relazione-tecnica.md)

### PWM e Potenziometro - 01 (2026-10-14) - Controllo della luminosità di un LED mediante PWM

- Consegna: controllare la luminosità di un LED collegato a un'uscita PWM di Arduino, facendola aumentare e diminuire gradualmente.
- Link soluzione: [esercizio 1](./2026-10-14-PWMPotenziometro/esercizio1.ino)
- Link simulazione: [simulazione Arduino](https://www.tinkercad.com/things/hJ0taRixAe0-2026-10-14-esercitazionepwm?sharecode=rBHUbySZ0d-Kyxzkz4yGtaLbYuAzG_OOnz8UdPDL4rw)
- Link relazione tecnica: [relazione tecnica e circuito](./2026-10-14-PWMPotenziometro/relazione_tecnica1.md)

### PWM e Potenziometro - 02 (2026-10-14) - Misurazione della tensione di un potenziometro

- Consegna: misurare la tensione in uscita da un potenziometro tramite l'ingresso analogico di Arduino e utilizzare il valore letto per controllare la frequenza di lampeggio del LED integrato.
- Link soluzione: [esercizio 2](./2026-10-14-PWMPotenziometro/esercizio2.ino)
- Link simulazione: [simulazione Arduino](https://www.tinkercad.com/things/aatgaTU9lTf-2026-10-14-esercitazionepotenziometro?sharecode=9VSyvcSaWcZFiDXdov-395C71Vjpqmv5ijsiXPDGv1k)
- Link relazione tecnica: [relazione tecnica e circuito](./2026-10-14-PWMPotenziometro/relazione_tecnica2.md)



## Warning

> ⚠️ **Attenzione**
>
> - Le soluzioni presenti sono proposte didattiche: possono esistere implementazioni diverse ugualmente corrette.
> - Alcuni programmi assumono input validi secondo la consegna; con input fuori specifica il comportamento potrebbe non essere significativo.
> - In base alla macroarea dell'esercizio la soluzione è designata sugli argomenti svolti fino a quel punto nel corso.
> - Per ogni esercitazione è presente una brevissima relazione tecnica volta a giustificare alcune scelte di progettazione e riassumere quanto fatto in laboratorio
> 

**Autore:** Ignazio Leonardo Calogero Sperandeo

by jimbug // :)
