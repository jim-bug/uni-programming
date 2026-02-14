;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-02-15
;		Consegna: Scrivere in assembly ARM 32 una subroutine che restituisca il numero di valori maggiori (o minori, altro esercizio capitato) di 15 dei rispettivi indici (es. Includere un esempio d'uso comprendente codice chiamante contenuti in un array di interi a 32 bit con segno, di lunghezza qualsiasi, passato come argomento e li sostituisca con i valori dei rispettivi indici.
;		by jim-bug // :)

START
    LDR     R0, =ARRAY                  
    MOV     R1, #4                      
    BL      CHECKANDSUBSTITUTE          
    END

CHECKANDSUBSTITUTE
    PUSH    {R4}                        
    MOV     R2, #0                      ; Indice corrente
    MOV     R3, #0                      ; Contatore valori > 15
    B       LOOP

LOOP
    CMP     R2, R1                      ; Confronta indice con lunghezza
    BGE     END_LOOP                    ; Se >= lunghezza, termina loop
    LDR     R4, [R0, R2, LSL #2]        ; Carica elemento array (offset = indice * 4)
    CMP     R4, #15                     ; Confronta elemento con 15
    BGT     GREATER                     ; Se > 15, salta a GREATER (o BMI per < 0)
    B       NEXT

GREATER
    STR     R2, [R0, R2, LSL #2]        
    ADD     R3, R3, #1                  

NEXT
    ADD     R2, R2, #1                  
    B       LOOP                        

END_LOOP
    POP     {R4}                        
    MOV     R0, R3
    MOV     PC, LR                      

ARRAY DCD 15, 16, 17, 18
    
