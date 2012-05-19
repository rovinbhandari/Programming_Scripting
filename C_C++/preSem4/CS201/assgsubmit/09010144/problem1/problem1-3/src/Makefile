
BIN="../bin"
INCLUDE="../include"
OBJ="../obj"


all : ${OBJ}/61.o ${OBJ}/61func.o
	g++ ${OBJ}/61.o ${OBJ}/61func.o -o ${BIN}/61

${OBJ}/61.o : 61.cpp
	g++ -c 61.cpp -o ${OBJ}/61.o

${OBJ}/61func.o : 61func.cpp
	g++ -c 61func.cpp -o ${OBJ}/61func.o
