CC=gcc

cflags=-g -c
oflags=-o

OBJ=./obj
SRC=./src
INC=./inc
BIN=./bin
iflags=-I$(INC)/

all: $(BIN)/server $(BIN)/client

$(BIN)/server: $(OBJ)/main_server.o $(OBJ)/server.o
	$(CC) $(oflags) $(BIN)/server $(OBJ)/main_server.o $(OBJ)/server.o

$(BIN)/client: $(OBJ)/main_client.o $(OBJ)/client.o
	$(CC) $(oflags) $(BIN)/client $(OBJ)/main_client.o $(OBJ)/client.o

$(OBJ)/main_server.o: $(SRC)/main_server.c
	$(CC) $(cflags) $(iflags) $(oflags) $(OBJ)/main_server.o $(SRC)/main_server.c

$(OBJ)/server.o: $(SRC)/server.c
	$(CC) $(cflags) $(iflags) $(oflags) $(OBJ)/server.o $(SRC)/server.c

$(OBJ)/main_client.o: $(SRC)/main_client.c
	$(CC) $(cflags) $(iflags) $(oflags) $(OBJ)/main_client.o $(SRC)/main_client.c

$(OBJ)/client.o: $(SRC)/client.c
	$(CC) $(cflags) $(iflags) $(oflags) $(OBJ)/client.o $(SRC)/client.c


clean:
	@echo "Cleaning in Progress"
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*
	rm -rf ./a.out
	@echo "Cleaning Done!"
