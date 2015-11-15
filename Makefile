project: program.o useprogram.o
	cc program.o useprogram.o -o project
program.o: program.c program.h
	cc -Wall -c program.c
useprogram.o: useprogram.c program.h
	cc -Wall -c useprogram.c
