CC = gcc 
CFLAGF = -Wall
LDFLAGS = -lsx
SRC = menu.c callback.c
PROG = menu
OBJS = $(SRC:.c=.o)
.SUFFIXES: .c .o 

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)


callback.o : callback.h
menu.o: menu.h callback.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)
