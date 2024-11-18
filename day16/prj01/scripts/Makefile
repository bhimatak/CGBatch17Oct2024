CC=gcc

cflags=-g -c
oflags=-o

OBJ=./obj
SRC=./src
INC=./inc
BIN=./bin
iflags=-I$(INC)/


$(BIN)/app: $(OBJ)/main.o $(OBJ)/emp.o
	$(CC) $(oflags) $(BIN)/app $(OBJ)/main.o $(OBJ)/emp.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(cflags) $(iflags) $(oflags) $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/emp.o: $(SRC)/emp.c
	$(CC) $(cflags) $(iflags) $(oflags) $(OBJ)/emp.o $(SRC)/emp.c


clean:
	@echo "Cleaning in Progress"
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*
	rm -rf ./a.out
	@echo "Cleaning Done!"
