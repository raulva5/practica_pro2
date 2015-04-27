tot: main agenda comanda crea

crea: main.o Agenda/Agenda.o Comanda/Comanda.o
	g++ -o main.x main.o Agenda/Agenda.o Comanda/Comanda.o

main: main.cc
	g++ -c -D_GLIBCXX_DEBUG main.cc

agenda: Agenda/Agenda.hh Agenda/Agenda.cc
	g++ -c -D_GLIBCXX_DEBUG Agenda/Agenda.cc

comanda: Comanda/Comanda.hh Comanda/Comanda.cc
	g++ -c -D_GLIBCXX_DEBUG Comanda/Comanda.cc


clean:
	rm *.o
	rm *.x