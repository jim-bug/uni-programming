;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2026-01-13
;		Consegna:  Scrivere in assembly ARM 32 una subroutine che riceva come unico argomento un intero con segno a 32 bit e restituisca il valore ottenuto moltiplicando l'argomento per 5.
;		by jim-bug // :)


MAIN
		MOV		R0, #10
		BL		MOL
		END
MOL
		ADD		R0, R0, R0, LSL #2  ; x * 5 => x * 4 + x, x * 4 lo calcolo facendo uno shift di 2 a sinistra
		MOV		PC, LR
