Jankenpo:	include/Head.h	source/obj/main.o source/obj/Player.o source/obj/Botao.o source/obj/Fabrica.o source/obj/Predio.o source/obj/Unidade.o source/obj/GeraRecursos.o source/obj/Jogo.o source/obj/Objeto.o 
	g++ -g -Og source/obj/main.o source/obj/Botao.o source/obj/Fabrica.o source/obj/Predio.o source/obj/Unidade.o source/obj/GeraRecursos.o source/obj/Jogo.o source/obj/Objeto.o source/obj/Player.o -o Jankenpo -lSDL2 -lSDL2_image -Iinclude -lSDL2_ttf -std=c++11
	
source/obj/main.o:	include/Jogo.h source/main.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/main.cpp -o source/obj/main.o -Iinclude -std=c++11

source/obj/Botao.o:		include/Jogo.h include/Botao.h source/Botao.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/Botao.cpp -o source/obj/Botao.o -Iinclude -std=c++11
	
source/obj/Fabrica.o:	include/Jogo.h include/Fabrica.h source/Fabrica.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/Fabrica.cpp -o source/obj/Fabrica.o -Iinclude -std=c++11
	
source/obj/Predio.o:	include/Jogo.h include/Predio.h source/Predio.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/Predio.cpp -o source/obj/Predio.o -Iinclude -std=c++11
	
source/obj/Unidade.o:	include/Jogo.h include/Unidade.h source/Unidade.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/Unidade.cpp -o source/obj/Unidade.o -Iinclude -std=c++11
	
source/obj/GeraRecursos.o:	include/Jogo.h include/GeraRecursos.h source/GeraRecursos.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/GeraRecursos.cpp -o source/obj/GeraRecursos.o -Iinclude -std=c++11
	
source/obj/Jogo.o:	include/Jogo.h source/Jogo.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/Jogo.cpp -o source/obj/Jogo.o -Iinclude -std=c++11
	
source/obj/Objeto.o:	include/Jogo.h include/Objeto.h source/Objeto.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/Objeto.cpp -o source/obj/Objeto.o -Iinclude -std=c++11
	
source/obj/Player.o:	include/Jogo.h include/Head.h	include/Player.h source/Player.cpp include/Botao.h include/Fabrica.h include/Predio.h include/Unidade.h include/GeraRecursos.h include/Objeto.h include/Head.h	include/Player.h
	g++ -c source/Player.cpp -o source/obj/Player.o -Iinclude -std=c++11
