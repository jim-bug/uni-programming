;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-10
;		Consegna:  Scrivere in assembly ARM 32 una subroutine (count_and_substitute) che restituisca il numero di valori negativi contenuti in un array di valori interi con segno a 32 bit passato come argomento e li sostituisca con un valore passato come ulteriore argomento. Il codice deve essere integrato nell'esempio d'uso indicato.
;		by jim-bug // :)

MAIN
        LDR     R0, =ARRAY
        MOV     R1, #4                   ; lunghezza array
        BL      COUNTANDSUBSTITUTE
        END
        
COUNTANDSUBSTITUTE
        PUSH {R4}                        ; salvo R4 nello stack
        MOV     R2, #0                   ; contatore numeri negativi
        MOV     R3, #5                   ; valore sostitutivo
        
LOOP
        LDR     R4, [R0], #4             ; leggo elemento con post-incremento
        CMP     R4, #0                   ; confronto con 0
        ADDMI   R2, R2, #1               ; se negativo, incremento contatore
        STRMI   R3, [R0, #-4]            ; se negativo, sostituisco valore
        SUBS    R1, R1, #1               ; decremento lunghezza
        BNE     LOOP                     ; continuo se R1 != 0
        MOV     R0, R2                   ; restituisco contatore in R0
        POP {R4}                         ; ripristino R4
        MOV     PC, LR

ARRAY   DCD     4, 4, 40, -45, -4