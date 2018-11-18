IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)


ODIR= obj
LDIR =../lib

LIBS=-lm

_DEPS = Unidade.h Objeto.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Unidade.o Objeto.o teste/testeUnidade.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 