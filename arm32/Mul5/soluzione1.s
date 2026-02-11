;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-13
;		Consegna:  Scrivere in assembly ARM 32 una subroutine che riceva come unico argomento un intero con segno a 32 bit e restituisca il valore ottenuto moltiplicando l'argomento per 5.
;		by jim-bug // :)


MAIN
        MOV     R0, #10                  ; valore da moltiplicare
        BL      MUL5
        END
        
MUL5
        ADD     R0, R0, R0, LSL #2       ; x * 5 = x + (x << 2) = x + x*4
        MOV     PC, LR                   ; restituisco risultato in R0
