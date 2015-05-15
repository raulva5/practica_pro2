program.x: program.cc Agenda/Agenda.hh Agenda/Agenda.cc Tasca/Tasca.hh Tasca/Tasca.cc Comanda/Comanda.hh Comanda/Comanda.cc Data/Data.hh Data/Data.cc Token/token.hh Token/token.cc
	g++ -c -D_GLIBCXX_DEBUG Data/Data.cc
	g++ -c -D_GLIBCXX_DEBUG Tasca/Tasca.cc
	g++ -c -D_GLIBCXX_DEBUG Token/token.cc
	g++ -c -D_GLIBCXX_DEBUG Comanda/Comanda.cc
	g++ -c -D_GLIBCXX_DEBUG Agenda/Agenda.cc
	g++ -c -D_GLIBCXX_DEBUG program.cc
	g++ -o program.x program.o Agenda.o Tasca.o Comanda.o Data.o token.o

clean:
	rm *.o
	rm *.x

sample1:
	./program.x << joc1.sample