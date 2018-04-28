boolCast: boolCast.o
    gcc -o boolCast boolCast.o

boolCast.o: boolCast.c
    gcc -c boolCast.c
