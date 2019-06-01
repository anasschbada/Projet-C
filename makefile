CC = gcc 
CFLAGF = -Wall -pedantic
LDFLAGS = -lsx
SRC = CardsGame.c menu.c callback.c data.c
PROG = CardsGame
OBJS = $(SRC:.c=.o)
.SUFFIXES: .c .o 

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

data.o: data.h
callback.o : callback.h
menu.o: menu.h 
CardsGame.o: menu.h callback.h data.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)
