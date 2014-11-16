IDIR =../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = priorityqueue.h graph.h dijkstra.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = priorityqueue.o graph.o dijkstra.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dijkstra: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
