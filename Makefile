Jankenpo:	include/Head.h	source/obj/main.o source/obj/Player.o source/obj/Botao.o source/obj/Fabrica.o source/obj/Predio.o source/obj/Unidade.o source/obj/GeraRecursos.o source/obj/Jogo.o source/obj/Objeto.o 
	g++ -g source/obj/main.o source/obj/Botao.o source/obj/Fabrica.o source/obj/Predio.o source/obj/Unidade.o source/obj/GeraRecursos.o source/obj/Jogo.o source/obj/Objeto.o source/obj/Player.o -o Jankenpo -lSDL2 -lSDL2_image -Iinclude -lSDL2_ttf
	
source/obj/main.o:	source/main.cpp
	g++ -c source/main.cpp -o source/obj/main.o -Iinclude

source/obj/Botao.o:	include/Botao.h source/Botao.cpp
	g++ -c source/Botao.cpp -o source/obj/Botao.o -Iinclude
	
source/obj/Fabrica.o:	include/Fabrica.h source/Fabrica.cpp
	g++ -c source/Fabrica.cpp -o source/obj/Fabrica.o -Iinclude
	
source/obj/Predio.o:	include/Predio.h source/Predio.cpp
	g++ -c source/Predio.cpp -o source/obj/Predio.o -Iinclude
	
source/obj/Unidade.o:	include/Unidade.h source/Unidade.cpp
	g++ -c source/Unidade.cpp -o source/obj/Unidade.o -Iinclude
	
source/obj/GeraRecursos.o:	include/GeraRecursos.h source/GeraRecursos.cpp
	g++ -c source/GeraRecursos.cpp -o source/obj/GeraRecursos.o -Iinclude
	
source/obj/Jogo.o:	include/Jogo.h source/Jogo.cpp
	g++ -c source/Jogo.cpp -o source/obj/Jogo.o -Iinclude
	
source/obj/Objeto.o:	include/Objeto.h source/Objeto.cpp
	g++ -c source/Objeto.cpp -o source/obj/Objeto.o -Iinclude
	
source/obj/Player.o:	include/Head.h	include/Player.h source/Player.cpp 
	g++ -c source/Player.cpp -o source/obj/Player.o -Iinclude
