;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna:  Scrivere in assembly ARM 32 una subroutine (count_and_substitute) che restituisca il numero di valori negativi contenuti in un array di valori interi con segno a 32 bit passato come argomento e li sostituisca con un valore passato come ulteriore argomento. Il codice deve essere integrato nell'esempio d'uso indicato.
;		by jim-bug // :)

START
					ldr		r0,=ARRAY
					mov		r1,#4
					mov		r2, #0      ; valore sostitutivo
					bl		COUNT_AND_SUBSTITUTE
					end
					
COUNT_AND_SUBSTITUTE
					
					mov		r3, #0      ; contatore numeri negativi
					mov		r4, #0      ; contatore ciclo
					
LOOP
					cmp		r4, r1      ; r4 >= r1 ?
					bge		END_LOOP
					
					ldr		r5, [r0, r4, lsl #2]
					cmp		r5, #0
					blt		NEGATIVE_NUMBER
					
					b		NEXT         ; salto l'incremento del contatore (dei numeri negativi) se array[r4] è positivo
					
NEGATIVE_NUMBER
					add		r3, r3, #1
					str		r2, [r0, r4, lsl #2]
					
NEXT
					add		r4, r4, #1
					b		LOOP
					
END_LOOP
					mov		r0, r3      
					mov		pc, LR
					
ARRAY				dcd		4,-3,-2,1