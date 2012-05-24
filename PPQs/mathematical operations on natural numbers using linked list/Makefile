CC = gcc
CFLAGS = -g -I./ -Wall
SRC = ../Sources/
BIN = ../bin/
BINSERVER = bin/server
OBJ = ../obj/
OBJECTS = ${OBJ}/Data.o ${OBJ}/Node.o ${OBJ}/LinkedList.o ${OBJ}/main.o
EXECUTABLE = ${BIN}/main.out

all: ${OBJECTS}
    ${CC} ${CFLAGS} $^ -o ${EXECUTABLECLIENT}

${OBJ}/%.o: ${SRC}/%.c
    ${CC} ${CFLAGS} -c $< -o $@
