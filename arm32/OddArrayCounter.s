;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna:  Scrivere in assembly ARM 32 una subroutine che riceva come argomenti due interi con segno a 32 bit e restituisca il minimo tra i due.
;		by jim-bug // :)


    MAIN 
        LDR R0, =ARRAY
        MOV R1, #4
        BL COUNT_ODD
        END

    COUNT_ODD
        MOV R2, #0                  ; contatore del ciclo
        MOV R3, #0                  ; contatore numeri dispari


    LOOP
        CMP R2, R1                  ; r2 >= r1 ?
        BGE END_LOOP
        
        LDR R4, [R0, R2, LSL #2]    ; leggo l'elemento dell'array, array[r2]
        ANDS R5, R4, #1             ; un modo per controllare se un numero è dipari è attraverso l'and bit a bit
        BNE ODD

        B NEXT                      ; salta l'incremento del contatore se il numero è pari


    ODD
        ADD R3, R3, #1              ; incremento il contatore dei numeri dispari
        STR R2, [R0, R2, LSL #2]    ; riscrivo l'elemento nell'array


    NEXT
        ADD R2, R2, #1              ; incremento l'indice
        B LOOP                      ; torno all'inizio del ciclo


    END_LOOP
    ;    MOV R0, R3                  ; restituisco il conteggio dei numeri dispari in R0
        MOV PC, LR


    ARRAY DCD 4, 7, 11, 2     