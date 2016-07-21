CC=gcc
SRC=../src
OBJ=../obj
BIN=.
INC=../inc
CFLAGS= -I $(INC) -Wall

all: reader

reader: utf8 helpers io parsing
	$(CC) $(CFLAGS) $@.c $(OBJ)/*.o -o $(BIN)/$@

utf8:
	$(CC) $(CFLAGS) -c $(SRC)/$@.c -o $(OBJ)/$@.o

helpers:
	$(CC) $(CFLAGS) -c $(SRC)/$@.c -o $(OBJ)/$@.o

io:
	$(CC) $(CFLAGS) -c $(SRC)/$@.c -o $(OBJ)/$@.o

parsing:
	$(CC) $(CFLAGS) -c $(SRC)/$@.c -o $(OBJ)/$@.o


clean:
	rm $(BIN)/*.exe
	rm $(OBJ)/*.o
