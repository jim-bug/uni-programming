;		Autore: Ignazio Leonardo Calogero Sperandeo
;		Data: 2025-12-19
;		Consegna:  Scrivere in assembly ARM 32 una subroutine che riceva come argomenti due interi con segno a 32 bit e restituisca il minimo tra i due.
;		by jim-bug // :)
		
    MAIN	
        MOV		R0, #10
        MOV		R1, #111
        BL MIN
        END
    MIN
        CMP		R0, R1
        MOVLE    R2, R0
        MOVGT    R2, R1
		
