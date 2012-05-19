BIN="../bin"
INCLUDE="../include"
OBJ="../obj"

all: ${OBJ}/61.o ${OBJ}/difference.o  ${OBJ}/dm.o ${OBJ}/61func.o
	g++ -g -o ${BIN}/output ${OBJ}/61.o ${OBJ}/difference.o ${OBJ}/dm.o ${OBJ}/61func.o

${OBJ}/61.o: 61.cpp
	g++ -c -g 61.cpp -o ${OBJ}/61.o
${OBJ}/difference.o:
	g++ -c -g difference.cpp -o ${OBJ}/difference.o	 

${OBJ}/dm.o:
	g++ -c -g dm.cpp -o ${OBJ}/dm.o
${OBJ}/61func.o:
	g++ -c -g 61func.cpp -o ${OBJ}/61func.o
