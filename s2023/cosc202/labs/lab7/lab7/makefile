
CC = g++
CFLAGS = -g -Wall
BIN = Prog7

all: $(BIN)

Prog7: bst.h Prog7.cpp
	$(CC) $(CFLAGS) -o Prog7 Prog7.cpp

.cpp: 
	$(CC) $(CFLAGS) -o $* $<

clean:
	rm -f $(BIN) *.o
