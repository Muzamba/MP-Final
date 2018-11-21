IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -lSDL2 -lSDL2_image -std=c++11


ODIR= obj
LDIR =../lib

LIBS=-lm

_DEPS = Unidade.h Head.h Fabrica.h Objeto.h Player.h Predio.h GeraRecursos.h Jogo.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  Player.o Objeto.o Unidade.o Predio.o Fabrica.o GeraRecursos.o Jogo.o Botao.o teste/testeGeraRecursos.o teste/testePlayer.o teste/testeUnidade.o teste/testeFabrica.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 