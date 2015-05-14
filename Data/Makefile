tot: main data compila

compila: main.o Data.o
	g++ -o main.x main.o Data.o

main: main.cc
	g++ -c -D_GLIBCXX_DEBUG main.cc

data: Data.hh Data.cc
	g++ -c -D_GLIBCXX_DEBUG Data.cc
	
clear:
	rm *.o
	rm *.x