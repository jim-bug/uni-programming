;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna: Scrivere in assembly ARM 32 una subroutine che riceva come argomenti due interi con segno a 32 bit e restituisca il minimo tra i due.
;		by jim-bug // :)

MAIN
        MOV     R0, #111                 ; primo intero
        MOV     R1, #10                  ; secondo intero
        BL      MIN
        END
        
MIN
        CMP     R0, R1                   ; confronto R0 e R1
        MOVGT   R0, R1                   ; se R0 > R1, sposto R1 in R0
        MOV     PC, LR                   ; restituisco il minimo in R0
