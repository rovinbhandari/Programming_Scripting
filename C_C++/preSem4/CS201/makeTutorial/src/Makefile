CC = gcc
CFLAG = -Wall
INCLUDE = -I 
LIBPATH = -L
LIB = -lm -ladd
OBJ = ../obj/
BIN = ../bin/



genlib: add.o
	ar -rcs ${OBJ}libadd.a ${OBJ}add.o

all: add.o test.o
	${CC} ${CFLAG} ${OBJ}test.o ${OBJ}add.o -o ${BIN}test ${LIB}

add.o:
	gcc -c add.c -o ${OBJ}add.o

test.o: 
	gcc -c test.c -o ${OBJ}test.o



clean:
	rm ${OBJ}*.o




	      	
