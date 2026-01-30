;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-31
;		Consegna: Scrivere in assembly ARM 32 una subroutine che dato un array, conta gli elementi con il bit 7 non settato e li sostituisce con un contatore progressivo.
;		by jim-bug // :)

MAIN
        LDR     R0, =ARRAY
        MOV     R1, #5                   ; lunghezza array
        BL      DIV_ARRAY
        END
        
DIV_ARRAY
        MOV     R2, #0                   ; indice i = 0
        MOV     R3, #0                   ; contatore
        
LOOP
        CMP     R2, R1                   ; r2 >= r1 ?
        BGE     END_LOOP
        
        LDR     R4, [R0, R2, LSL #2]     ; leggo l'elemento dell'array, array[r4]
        TST     R4, #128
        BEQ     COND
        B       NEXT
        
COND
        ADD     R3, R3, #1
        STR     R3, [R0, R2, LSL #2]
        
NEXT
        ADD     R2, R2, #1               ; incremento l'indice
        B       LOOP
        
END_LOOP
        MOV     PC, LR
        
ARRAY   DCD     4, 4, 4, 4, 4