;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-31
;		Consegna: Scrivere in assembly ARM 32 una subroutine che dato un array, conta gli elementi con il bit 7 non settato e li sostituisce con un contatore progressivo.
;		by jim-bug // :)

MAIN
        LDR     R0, =ARRAY
        MOV     R1, #4                   ; lunghezza array
        BL      CHECKBIT
        END
        
CHECKBIT
        MOV     R2, #0                   ; contatore numeri con il bit 7 posto a 0
        
LOOP
        LDR     R3, [R0], #4             ; leggo elemento con post-incremento
        TST     R3, #128                 ; testo il bit 7 (valore 128)
        ADDEQ   R2, R2, #1               ; se bit 7 = 0, incremento contatore
        STREQ   R2, [R0, #-4]            ; scrivo contatore nell'array
        SUBS    R1, R1, #1               ; decremento lunghezza array
        BNE     LOOP                     ; continuo se R1 != 0
        MOV     R0, R2                   ; restituisco il contatore in R0
        MOV     PC, LR

ARRAY   DCD     64, 32, 16, 128