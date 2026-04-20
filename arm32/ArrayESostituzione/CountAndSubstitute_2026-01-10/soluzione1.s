;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-10
;		Consegna:  Scrivere in assembly ARM 32 una subroutine (count_and_substitute) che restituisca il numero di valori negativi contenuti in un array di valori interi con segno a 32 bit passato come argomento e li sostituisca con un valore passato come ulteriore argomento. Il codice deve essere integrato nell'esempio d'uso indicato.
;		by jim-bug // :)

MAIN
        LDR     R0, =ARRAY
        MOV     R1, #4                   ; lunghezza array
        MOV     R2, #0                   ; valore sostitutivo
        BL      COUNT_AND_SUBSTITUTE
        END
        
COUNT_AND_SUBSTITUTE
        PUSH {R4}
        MOV     R3, #0                   ; contatore numeri negativi
        MOV     R4, #0                   ; indice ciclo
        
LOOP
        CMP     R4, R1                   ; R4 >= R1 ?
        BGE     END_LOOP
        
        LDR     R5, [R0, R4, LSL #2]     ; leggo elemento array[R4]
        CMP     R5, #0                   ; confronto con 0
        BLT     NEGATIVE_NUMBER          ; se negativo, vai a NEGATIVE_NUMBER
        
        B       NEXT                     ; altrimenti salta
        
NEGATIVE_NUMBER
        ADD     R3, R3, #1               ; incremento contatore negativi
        STR     R2, [R0, R4, LSL #2]     ; sostituisco con valore sostitutivo
        
NEXT
        ADD     R4, R4, #1               ; incremento indice
        B       LOOP
        
END_LOOP
        POP {R4}
        MOV     R0, R3                   ; restituisco contatore in R0
        MOV     PC, LR
        
ARRAY   DCD     4, -3, -2, 1