;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-02-15
;		Consegna: Scrivere in assembly ARM 32 una subroutine che restituisca il numero di valori maggiori (o minori, altro esercizio capitato) di 15 dei rispettivi indici (es. Includere un esempio d'uso comprendente codice chiamante contenuti in un array di interi a 32 bit con segno, di lunghezza qualsiasi, passato come argomento e li sostituisca con i valori dei rispettivi indici.
;		by jim-bug // :)

START
    LDR     R0, =ARR                    
    MOV     R1, #4                      
    BL      CHECKANDSUBSTITUTE          
    END

CHECKANDSUBSTITUTE
    PUSH    {R4}                        
    MOV     R2, #0                     
    MOV     R3, #0                      
    B       LOOP

LOOP
    LDR     R4, [R0], #4                ; Carica elemento e incrementa puntatore
    CMP     R4, #15                     ; Confronta con 15
    ADDGT   R2, R2, #1                  ; Se > 15: incrementa contatore (o ADDMI nel caso dell'altro esercizio)
    STRGT   R3, [R0, #-4]               ; Se > 15: sostituisce con indice (o STRMI nel caso dell'altro esercizio)
    ADD     R3, R3, #1                  
    SUBS    R1, R1, #1                   
    BNE     LOOP                        
    
    POP     {R4}                        
    MOV     R0, R2                      
    MOV     PC, LR    

ARR DCD 15, 16, 17, 18                  
    