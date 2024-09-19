
CC = g++ -Wall
BIN = Prog1a Prog1b Prog1c

all: $(BIN)

Prog1a: Prog1a.cpp
	$(CC) $(CFLAGS) -o $@ Prog1a.cpp

Prog1b: Prog1b.cpp
	$(CC) $(CFLAGS) -o $@ Prog1b.cpp

Prog1c: Prog1c.cpp Support.h Support.cpp
	$(CC) $(CFLAGS) -o $@ Prog1c.cpp Support.cpp

clean:
	rm -f $(BIN)
