tot:  tasca data comanda token agenda main crea

crea: main.o Agenda.o Tasca.o Comanda.o Data.o token.o
	g++ -o main.x main.o Agenda.o Tasca.o Comanda.o Data.o token.o

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

token: Token/token.hh Token/token.cc
	g++ -c -D_GLIBCXX_DEBUG Token/token.cc


clean:
	rm *.o
	rm *.x
sample1:
	./main.x << joc1.sample

sample2:
	./main.x << joc2.sample