
CC = g++ -Wall
BIN = ProgX

all: $(BIN)

ProgX: ProgX.cpp Support.h Support.cpp
	$(CC) $(CFLAGS) -o $@ ProgX.cpp Support.cpp

clean:
	rm -f $(BIN)
