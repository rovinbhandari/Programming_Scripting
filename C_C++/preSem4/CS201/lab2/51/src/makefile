BIN="../bin"
INCLUDE="../include"
OBJ="../obj"

all: ${OBJ}/main.o ${OBJ}/difference.o
	g++ -g -o ${BIN}/output ${OBJ}/main.o ${OBJ}/difference.o

${OBJ}/main.o: main.cpp
	g++ -c -g main.cpp -o ${OBJ}/main.o
${OBJ}/difference.o:
	g++ -c -g difference.cpp -o ${OBJ}/difference.o	 
