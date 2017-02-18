zeta0: main.o zeta0.o utest.o vtest.o
	g++ -o zeta0 main.o zeta0.o utest.o vtest.o

main.o: main.cpp zeta0.h
	g++ -c main.cpp

zeta0.o: zeta0.cpp zeta0.h
	g++ -c zeta0.cpp

utest.o: utest.cpp zeta0.h
	g++ -c utest.cpp

vtest.o: vtest.cpp zeta0.h
	g++ -c vtest.cpp

