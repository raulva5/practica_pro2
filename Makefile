program.exe: Tasca.o Temps.o Agenda.o comanda.o token.o program.o
	g++ -o program.exe Tasca.o Temps.o token.o comanda.o Agenda.o program.o

program.x: Tasca.o Temps.o Agenda.o comanda.o token.o program.o
	g++ -o program.x Tasca.o Temps.o token.o comanda.o Agenda.o program.o

Tasca.o: Tasca.hh Tasca.cc
	g++ -c -D_GLIBCXX_DEBUG Tasca.cc

Temps.o: Temps.hh Temps.cc
	g++ -c -D_GLIBCXX_DEBUG Temps.cc

Agenda.o: Agenda.hh Agenda.cc
	g++ -c -D_GLIBCXX_DEBUG Agenda.cc

token.o: token.hh token.cc
	g++ -c  -D_GLIBCXX_DEBUG token.cc

comanda.o: comanda.hh comanda.cc
	g++ -c  -D_GLIBCXX_DEBUG comanda.cc

program.o: program.cc
	g++ -c -D_GLIBCXX_DEBUG program.cc

provisional:
	tar -cvf practica.tar Temps.* Agenda.* Tasca.* program.cc Makefile

practica.tar:
	tar -cvf practica.tar Temps.* Agenda.* Tasca.* program.cc Makefile equip.pdf jp_*

clean:
	rm *.o
	rm *.x