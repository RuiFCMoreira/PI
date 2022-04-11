f8 : main.o Stack.o Listas.o Queue.o
	gcc -o f8 main.o Stack.o Listas.o Queue.o
	rm *.o

main.o : main.c Stack.c
	gcc -c main.c

Stack.o : Stack.c Stack.h Listas.h
	gcc -c Stack.c

Listas.o : Listas.c Listas.h
	gcc -c Listas.c

Queue.o : Queue.c Queue.h Listas.h
	gcc -c Queue.c

