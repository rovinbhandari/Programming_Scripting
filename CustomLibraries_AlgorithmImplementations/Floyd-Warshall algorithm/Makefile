CC=gcc
CFLAGS=-Wall -g -I./
SRC=.
OBJ=.
BIN=.

OBJECTS=$(OBJ)/FloydWarshall.o $(OBJ)/main.o
OUTPUT=$(BIN)/FWdemo.out

all: clean $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(OUTPUT)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)/*.o
	rm -f $(OUTPUT)

