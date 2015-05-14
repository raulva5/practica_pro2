tot: main tasca compila

compila: main.o Tasca.o
	g++ -o main.x main.o Tasca.o

main: main.cc
	g++ -c -D_GLIBCXX_DEBUG main.cc

tasca: Tasca.hh Tasca.cc
	g++ -c -D_GLIBCXX_DEBUG Tasca.cc
	
clear:
	rm *.o
	rm *.x