;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-31
;		Consegna: Scrivere in assembly ARM 32 una subroutine che dato un array restituisca il numero di elementi negativi dopo aver sottratto un numero arbitrario da ogni elemento.
;		by jim-bug // :)

		
MAIN
        LDR     R0, =ARRAY
        MOV     R1, #5                   ; lunghezza array
        BL      SUB_ARRAY
        END
        
SUB_ARRAY
        MOV     R2, #0                   ; indice i = 0
        MOV     R3, #15                  ; valore da sottrarre
        MOV     R5, #0                   ; contatore numeri negativi
        
LOOP
        CMP     R2, R1                   ; R2 >= R1 ?
        BGE     END_LOOP
        
        LDR     R4, [R0, R2, LSL #2]     ; leggo elemento array[R2]
        SUB     R4, R4, R3               ; sottraggo valore
        STR     R4, [R0, R2, LSL #2]     ; scrivo risultato nell'array
        CMP     R4, #0                   ; confronto con 0
        BMI     INCREMENT                ; se negativo, incremento contatore
        B       NEXT
        
INCREMENT
        ADD     R5, R5, #1               ; incremento contatore negativi
        
NEXT
        ADD     R2, R2, #1               ; incremento indice
        B       LOOP
        
END_LOOP
        MOV     R0, R5                   ; restituisco contatore in R0
        MOV     PC, LR
        
ARRAY   DCD     4, 4, 4, 4, 4