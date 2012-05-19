SRC = .
OBJ = .
BIN = .

CC = gcc
CFLAGS = -Wall -g
CINCLUDES = -I./
CLINKS = -lm

OBJECTS = $(OBJ)/sudokusolver.o $(OBJ)/main.o
OUTPUT = $(BIN)/sudokusolver.out

all:	clean $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $(OBJECTS) -o $(OUTPUT) $(CLINKS)

$(OBJ)/%.o:	$(SRC)/%.c
		$(CC) $(CFLAGS) -c $(CINCLUDES) $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(OUTPUT)
