mach0: main.o mach0.o utest.o vtest.o
	g++ -o mach0 main.o mach0.o utest.o vtest.o

main.o: main.cpp mach0.h
	g++ -c main.cpp

mach0.o: mach0.cpp mach0.h
	g++ -c mach0.cpp

utest.o: utest.cpp utest.h
	g++ -c utest.cpp

vtest.o: vtest.cpp vtest.h
	g++ -c vtest.cpp

