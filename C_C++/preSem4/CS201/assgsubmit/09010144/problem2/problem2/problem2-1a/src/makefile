BIN="../bin"
INCLUDE="../include"
OBJ="../obj"

all: ${OBJ}/main.o ${OBJ}/slist.o
	g++ -o ${BIN}/output ${OBJ}/main.o ${OBJ}/slist.o

${OBJ}/main.o: main.cpp
	g++ -c main.cpp -o ${OBJ}/main.o
${OBJ}/difference.o:
	g++ -c slist.cpp -o ${OBJ}/slist.o	 
