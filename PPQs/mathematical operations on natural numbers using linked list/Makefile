CC = gcc
CFLAGS = -g -I./ -Wall
SRC = .
BIN = ./bin
BINSERVER = bin/server
OBJ = ./obj
OBJECTS = ${OBJ}/Data.o ${OBJ}/Node.o ${OBJ}/LinkedList.o ${OBJ}/operations.o ${OBJ}/main.o
EXECUTABLE = ${BIN}/main.out

all: ${OBJECTS}
	${CC} ${CFLAGS} $^ -o ${EXECUTABLE}

${OBJ}/%.o: ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJECTS}
	rm -f ${EXECUTABLE}
