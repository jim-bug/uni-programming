;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-31
;		Consegna: Scrivere in assembly ARM 32 una subroutine che dato un array restituisca il numero di elementi negativi dopo aver sottratto un numero arbitrario da ogni elemento.
;		by jim-bug // :)


MAIN
        LDR     R0, =ARRAY
        MOV     R1, #4                   ; lunghezza array
        BL      SUBREG
        END
        
SUBREG
        PUSH {R4}
        MOV     R2, #0                   ; contatore numeri negativi
        MOV     R3, #15                  ; valore da sottrarre
        
LOOP
        LDR     R4, [R0], #4             ; leggo elemento con post-incremento
        SUBS    R4, R4, R3               ; sottraggo valore (aggiorna flag)
        STR     R4, [R0, #-4]            ; scrivo risultato nell'array
        ADDMI   R2, R2, #1               ; se negativo, incremento contatore
        SUBS    R1, R1, #1               ; decremento lunghezza
        BNE     LOOP                     ; continuo se R1 != 0
        POP {R4}                         ; ripristino R4
        MOV     R0, R2                   ; restituisco contatore in R0
        MOV     PC, LR

ARRAY   DCD     325, 56, 77, 88