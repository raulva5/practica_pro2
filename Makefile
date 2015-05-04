tot: main agenda tasca comanda data token crea

crea: main.o Agenda/Agenda.o Comanda/Comanda.o
	g++ -o main.x main.o Agenda/Agenda.o Tasca/Tasca.o Comanda/Comanda.o Data/Data.o Token/Token.o

main: main.cc
	g++ -c -D_GLIBCXX_DEBUG main.cc

agenda: Agenda/Agenda.hh Agenda/Agenda.cc
	g++ -c -D_GLIBCXX_DEBUG Agenda/Agenda.cc

tasca: Tasca/Tasca.hh Tasca/Tasca.cc
	g++ -c -D_GLIBCXX_DEBUG Tasca/Tasca.cc

comanda: Comanda/Comanda.hh Comanda/Comanda.cc
	g++ -c -D_GLIBCXX_DEBUG Comanda/Comanda.cc

data: Data/Data.hh Data/Data.cc
	g++ -c -D_GLIBCXX_DEBUG Data/Data.cc

token: Token/Token.hh Token/Token.cc
	g++ -c -D_GLIBCXX_DEBUG Token/Token.cc


clean:
	rm *.o
	rm *.x