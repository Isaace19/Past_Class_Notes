
CC = g++
CFLAGS = -Wall
BIN = Prog8

all: $(BIN)

Prog8: Prog8.cpp Support.h Support.cpp
	$(CC) $(CFLAGS) -o $@ Prog8.cpp Support.cpp

clean:
	rm -f $(BIN)
