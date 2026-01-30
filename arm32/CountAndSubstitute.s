;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-10
;		Consegna:  Scrivere in assembly ARM 32 una subroutine (count_and_substitute) che restituisca il numero di valori negativi contenuti in un array di valori interi con segno a 32 bit passato come argomento e li sostituisca con un valore passato come ulteriore argomento. Il codice deve essere integrato nell'esempio d'uso indicato.
;		by jim-bug // :)

START
					LDR		R0, =ARRAY
					MOV		R1, #4
					MOV		R2, #0               ; valore sostitutivo
					BL		COUNT_AND_SUBSTITUTE
					END
					
COUNT_AND_SUBSTITUTE
					
					MOV		R3, #0               ; contatore numeri negativi
					MOV		R4, #0               ; contatore ciclo
					
LOOP
					CMP		R4, R1               ; R4 >= R1 ?
					BGE		END_LOOP
					
					LDR		R5, [R0, R4, LSL #2]
					CMP		R5, #0
					BLT		NEGATIVE_NUMBER
					
					B		NEXT                 ; salto l'incremento del contatore (dei numeri negativi) se array[R4] è positivo
					
NEGATIVE_NUMBER
					ADD		R3, R3, #1
					STR		R2, [R0, R4, LSL #2]
					
NEXT
					ADD		R4, R4, #1
					B		LOOP
					
END_LOOP
					MOV		R0, R3      
					MOV		PC, LR
					
ARRAY				DCD		4, -3, -2, 1