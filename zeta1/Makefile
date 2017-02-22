zeta1: main.o test.o
	mpiCC -o zeta1 main.o test.o

main.o: main.cpp zeta1.h
	mpiCC -c main.cpp

test.o: test.cpp zeta1.h
	mpiCC -c test.cpp

