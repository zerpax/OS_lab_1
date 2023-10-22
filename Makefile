the: child.o parent.o main.o
	gcc -o the main.o parent.o child.o
main.o: child.h parent.h main.c
	gcc -c main.c
child.o: child.c child.h
	gcc -c child.c
parent.o: parent.c parent.h
	gcc -c parent.c
