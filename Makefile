CC= g++
CFLAGS= -Wall -pedantic -g
RM= rm -rf

all: sim

sim: Access.o Cache.o Memory.o Set.o Block.o matrix/aware.o matrix/unaware.o matrix/oblivious.o main.cpp
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o matrix/*.o
	$(RM) sim
