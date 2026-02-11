;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna: Scrivere in assembly ARM 32 una subroutine che riceva come unico argomento un valore intero con segno a 32 bit e restituisca il valore ricevuto cambiato di segno.
;		by jim-bug // :)

MAIN
        MOV     R0, #5                   ; valore da negare
        BL      NEGATE
        END
        
NEGATE
        RSB     R0, R0, #0               ; reverse subtract: R0 = 0 - R0
        MOV     PC, LR                   ; restituisco valore negato in R0
