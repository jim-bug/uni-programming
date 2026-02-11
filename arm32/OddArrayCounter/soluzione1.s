;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna:  Scrivere in assembly ARM 32 una subroutine che restituisca il numero di valori dispari contenuti in un array di valori interi senza segno a 32 bit, di lunghezza qualsiasi, passato come argomento e li sostituisca con i valori dei rispettivi indici.
;		by jim-bug // :)


MAIN
        LDR     R0, =ARRAY
        MOV     R1, #4                   ; lunghezza array
        BL      COUNT_ODD
        END
        
COUNT_ODD
        PUSH {R4, R5}
        MOV     R2, #0                   ; indice corrente
        MOV     R3, #0                   ; contatore numeri dispari
        
LOOP
        CMP     R2, R1                   ; R2 >= R1 ?
        BGE     END_LOOP
        
        LDR     R4, [R0, R2, LSL #2]     ; leggo elemento array[R2]
        ANDS    R5, R4, #1               ; testo bit 0 per verificare se dispari
        BNE     ODD                      ; se dispari, vai a ODD
        
        B       NEXT                     ; altrimenti salta
        
ODD
        ADD     R3, R3, #1               ; incremento contatore dispari
        STR     R2, [R0, R2, LSL #2]     ; sostituisco con indice
        
NEXT
        ADD     R2, R2, #1               ; incremento l'indice
        B       LOOP
        
END_LOOP
        POP {R4, R5}                     ; ripristino registri
        MOV     R0, R3                   ; restituisco conteggio in R0
        MOV     PC, LR
        
ARRAY   DCD     4, 7, 11, 2 