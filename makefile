all: stringfunc.o main.o
	gcc -o Str stringfunc.o main.o

stringfunc.o: stringfunc.c stringfunc.h
	gcc -c stringfunc.c

main.o: main.c stringfunc.h
	gcc -c main.c

run:
	./Str

clean:
	rm *.o