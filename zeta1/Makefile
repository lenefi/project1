CC=g++
CFLAGS = -std=c99 -O2
LDFLAGS= 
LNKLIBS= -lm

MPIRUN =mpirun
NPROCS?=4

EXE=exe
EXESRC=main.cpp
EXEOBJ=$(patsubst %.cpp, %.o, $(EXESRC))
CLEAN_FILES+=$(EXE) $(EXEOBJ)

LIB=libfunction.a
LIBSRC=zeta1.cpp test.cpp
LIBOBJ=$(patsubst %.cpp, %.o, $(LIBSRC))
CLEAN_FILES+=$(LIB) $(LIBOBJ)

# Implicit rule for compilation of all objects
%.o:%.c
	$(CC) $(CFLAGS) -c $<

# Rule to build the library
$(LIB): $(LIBOBJ)
	@echo "LIB $@"
	@ar r $@ $^


# Program
$(EXE):	$(EXEOBJ) $(LIB)
	@echo "EXE $@"
	@$(CC) $(LDFLAGS) -o $@ $^ $(LNKLIBS)

run:	$(EXE)
	$(MPIRUN) -n $(NPROCS) ./$< $(X) $(N)

clean:
	rm -f $(CLEAN_FILES)
