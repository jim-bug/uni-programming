;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna:  Scrivere in assembly ARM 32 una subroutine che restituisca il numero di valori dispari contenuti in un array di valori interi senza segno a 32 bit, di lunghezza qualsiasi, passato come argomento e li sostituisca con i valori dei rispettivi indici.
;		by jim-bug // :)


MAIN
        LDR     R0, =ARRAY
        MOV     R1, #4                   ; lunghezza array
        BL      ODD
        END
        
ODD
        PUSH {R4}
        MOV     R2, #0                   ; indice corrente
        MOV     R3, #0                   ; contatore dispari
        
LOOP
        LDR     R4, [R0], #4             ; leggo elemento con post-incremento
        TST     R4, #1                   ; testo bit 0 per verificare se dispari
        ADDNE   R3, R3, #1               ; se dispari, incremento contatore
        STRNE   R2, [R0, #-4]            ; se dispari, sostituisco con indice
        ADD     R2, R2, #1               ; incremento sempre l'indice
        SUBS    R1, R1, #1               ; decremento lunghezza
        BNE     LOOP                     ; continuo se R1 != 0
        POP {R4}                         ; ripristino R4
        MOV     R0, R3                   ; restituisco conteggio in R0
        MOV     PC, LR

ARRAY   DCD     1, 2, 3, 4, 5
