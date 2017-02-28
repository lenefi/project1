mach1: main.o mach1.o 
	mpiCC -o mach1 main.o mach1.o

main.o: main.cpp mach1.h
	mpiCC -c main.cpp

mach1.o: mach1.cpp mach1.h
	mpiCC -c mach1.cpp

