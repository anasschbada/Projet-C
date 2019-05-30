CC = gcc 
CFLAGF = -Wall
LDFLAGS = -lsx
SRC = menu.c
PROG = menu
OBJS = $(SRC:.c=.o)
.SUFFIXES: .c .o 

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

menu.o: menu.h
%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ core $(PROG)
