;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna:  Scrivere in assembly ARM 32 una subroutine che modifichi un array, di lunghezza non predefinita, di valori interi senza segno a 32 bit, passato come argomento, dividendo ciascun valore per 4.
;		by jim-bug // :)


MAIN
        LDR     R0, =ARRAY
        MOV     R1, #5                   ; lunghezza array
        BL      DIV_ARRAY
        END
        
DIV_ARRAY
        MOV     R2, #0                   ; indice i = 0
        
LOOP
        CMP     R2, R1                   ; r2 >= r1 ?
        BGE     END_LOOP
        
        LDR     R3, [R0, R2, LSL #2]     ; leggo l'elemento dell'array, array[r2]
        LSR     R3, R3, #2               ; divido per 4 (Logical Shift Right)
        STR     R3, [R0, R2, LSL #2]     ; riscrivo l'elemento nell'array
        
        ADD     R2, R2, #1               ; incremento l'indice
        B       LOOP                     ; torno all'inizio del ciclo
        
END_LOOP
        MOV     PC, LR
        
ARRAY   DCD     4, 4, 4, 4, 4


