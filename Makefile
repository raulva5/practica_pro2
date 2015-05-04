tot: main token agenda tasca comanda crea

crea: main.o Agenda/Agenda.o Comanda/Comanda.o
	g++ -o main.x main.o Agenda/Agenda.o Comanda/Comanda.o

main: main.cc
	g++ -c -D_GLIBCXX_DEBUG main.cc

agenda: Agenda/Agenda.hh Agenda/Agenda.cc
	g++ -c -D_GLIBCXX_DEBUG Agenda/Agenda.cc

tasca: Tasca/Tasca.hh Tasca/Tasca.cc
	g++ -c -D_GLIBCXX_DEBUG Tasca/Tasca.cc

comanda: Comanda/Comanda.hh Comanda/Comanda.cc
	g++ -c -D_GLIBCXX_DEBUG Comanda/Comanda.cc

token: Token/Token.hh Token/Token.cc
	g++ -c -D_GLIBCXX_DEBUG Token/Token.cc


clean:
	rm *.o
	rm *.x