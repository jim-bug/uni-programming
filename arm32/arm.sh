#!/bin/bash
# Autore: Ignazio Leonardo Calogero Sperandeo
# Data: 2025-12-15
# eseguiamo arm32!!!
# by jim-bug // :)

get_command(){
	echo -e "info registers:\t Mostra registri\nstepi:\tAvanti di un istruzione\nx/4i $ pc: Prossime istruzioni\n"
}

if [ "$1" = "-h" ]; then
	get_command
else
	arm-linux-gnueabihf-as $1 -o $1.o
	arm-linux-gnueabihf-ld $1.o -o $1.arm
	rm $1.o
	qemu-arm -g 1122 ./$1.arm &
	gdb-multiarch $1.arm -ex "target remote :1122"
fi

# // :)


