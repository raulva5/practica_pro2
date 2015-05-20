COMPILACION_JUTGE = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: Tasca.o Data.o Agenda.o comanda.o token.o program.o
	g++ -o program.exe Tasca.o Data.o token.o comanda.o Agenda.o program.o

program.x: Tasca.o Data.o Agenda.o comanda.o token.o program.o
	g++ -o program.x Tasca.o Data.o token.o comanda.o Agenda.o program.o

Tasca.o: Tasca.hh Tasca.cc
	g++ -c  $(COMPILACION_JUTGE) Tasca.cc

Data.o: Data.hh Data.cc
	g++ -c  $(COMPILACION_JUTGE) Data.cc

Agenda.o: Agenda.hh Agenda.cc
	g++ -c  $(COMPILACION_JUTGE) Agenda.cc

program.o: program.cc
	g++ -c  $(COMPILACION_JUTGE) program.cc

practica.tar:
	tar -cvf practica.tar Data.* Agenda.* Tasca.* program.cc Makefile

token.o: token.hh token.cc
	g++ -c  $(COMPILACION_JUTGE) token.cc

comanda.o: comanda.hh comanda.cc
	g++ -c  $(COMPILACION_JUTGE) comanda.cc

clean:
	rm *.o
	rm *.x
