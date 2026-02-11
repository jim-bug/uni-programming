;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-31
;		Consegna: Scrivere in assembly ARM 32 una subroutine che dato un array, conta gli elementi con il bit 7 non settato e li sostituisce con un contatore progressivo.
;		by jim-bug // :)

MAIN
        LDR     R0, =ARRAY
        MOV     R1, #5                   ; lunghezza array
        BL      CHECKBIT
        END
        
CHECKBIT
        PUSH {R4}
        MOV     R2, #0                   ; indice i = 0
        MOV     R3, #0                   ; contatore
        
LOOP
        CMP     R2, R1                   ; R2 >= R1 ?
        BGE     END_LOOP
        
        LDR     R4, [R0, R2, LSL #2]     ; leggo l'elemento dell'array, array[R2]
        TST     R4, #128                 ; testo il bit 7 (valore 128)
        BEQ     COND                     ; se bit 7 = 0, vai a COND
        B       NEXT
        
COND
        ADD     R3, R3, #1               ; incremento contatore
        STR     R3, [R0, R2, LSL #2]     ; sostituisco elemento con contatore
        
NEXT
        ADD     R2, R2, #1               ; incremento l'indice
        B       LOOP
        
END_LOOP
        POP {R4}
        MOV     PC, LR
        
ARRAY   DCD     4, 4, 4, 4, 4