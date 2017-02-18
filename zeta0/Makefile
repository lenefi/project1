zeta0: main.o zeta0.o utest.o
	g++ -o zeta0 main.o zeta0.o utest.o

main.o: main.cpp zeta0.h
	g++ -c main.cpp

zeta0.o: zeta0.cpp zeta0.h
	g++ -c zeta0.cpp

utest.o: utest.cpp zeta0.h
	g++ -c utest.cpp

