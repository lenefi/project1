#include <iostream>
#include "mpi.h"
#include <cstring>
#include "zeta1.h"

void test(){

int size, rank;

MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);


std::cout<< "number of processes: " << size<< "\n";

}
