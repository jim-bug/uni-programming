;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna:  Scrivere in assembly ARM 32 una subroutine che modifichi un array, di lunghezza non predefinita, di valori interi senza segno a 32 bit, passato come argomento, dividendo ciascun valore per 4.
;		by jim-bug // :)


MAIN
        LDR     R0, =ARRAY
        MOV     R1, #4                   ; lunghezza array
        BL      DIV_ARRAY
        END
        
DIV_ARRAY
LOOP
        LDR     R2, [R0], #4             ; leggo elemento con post-incremento
        LSR     R2, R2, #2               ; divido per 4 (shift right di 2)
        STR     R2, [R0, #-4]            ; scrivo risultato nell'array
        SUBS    R1, R1, #1               ; decremento lunghezza
        BNE     LOOP                     ; continuo se R1 != 0
        MOV     PC, LR
        
ARRAY   DCD     4, 4, 4, 4, 4