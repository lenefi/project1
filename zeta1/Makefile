zeta1: main.o zeta1.o
	mpiCC -o zeta1 main.o zeta1.o

main.o: main.cpp zeta1.h
	mpiCC -c main.cpp

zeta1.o: zeta1.cpp zeta1.h
	mpiCC -c zeta1.cpp

