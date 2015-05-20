program.exe: Tasca.o Data.o Agenda.o comanda.o token.o program.o
	g++ -o program.exe Tasca.o Data.o token.o comanda.o Agenda.o program.o

program.x: Tasca.o Data.o Agenda.o comanda.o token.o program.o
	g++ -o program.x Tasca.o Data.o token.o comanda.o Agenda.o program.o

Tasca.o: Tasca.hh Tasca.cc
	g++ -c Tasca.cc

Data.o: Data.hh Data.cc
	g++ -c Data.cc

Agenda.o: Agenda.hh Agenda.cc
	g++ -c Agenda.cc

program.o: program.cc
	g++ -c program.cc

practica.tar:
	tar -cvf practica.tar Data.* Agenda.* Tasca.* program.cc Makefile

clean:
	rm *.o
	rm *.x