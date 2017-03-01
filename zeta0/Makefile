CC=g++
CFLAGS = -O2
LDFLAGS= 
LNKLIBS= -lm

MPIRUN =mpirun
NPROCS?=1

EXE=exe
EXESRC=main.cpp
EXEOBJ=$(patsubst %.cpp, %.o, $(EXESRC))
CLEAN_FILES+=$(EXE) $(EXEOBJ)

LIB=libfunction.a
LIBSRC=zeta0.cpp
LIBOBJ=$(patsubst %.cpp, %.o, $(LIBSRC))
CLEAN_FILES+=$(LIB) $(LIBOBJ)

CLEAN_FILES+= utest utest.o
CLEAN_FILES+= vtest vtest.o

# Implicit rule for compilation of all objects
%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

# Rule to build the library
$(LIB): $(LIBOBJ)
	@echo "LIB $@"
	@ar r $@ $^

all:	$(EXE) utest vtest

# Program
$(EXE):	$(EXEOBJ) $(LIB)
	@echo "EXE $@"
	@$(CC) $(LDFLAGS) -o $@ $^ $(LNKLIBS)

run:	$(EXE)
	$(MPIRUN) -n $(NPROCS) ./$< $(X) $(N)

# Unit test
utest:	utest.o $(LIB)
	@echo "EXE $@"
	@$(CC) $(LDFLAGS) -o $@ $^ $(LNKLIBS)
	./$@

# Verification test
vtest:	vtest.o $(LIB)
	@echo "EXE $@"
	@$(CC) $(LDFLAGS) -o $@ $^ $(LNKLIBS)
	./$@

clean:
	rm -f $(CLEAN_FILES)
