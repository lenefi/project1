#include <iostream>
#include <mpi.h>
#include "zeta1.h"

int main (int argc, char **argv){

MPI_Status status;

MPI_Init(&argc,&argv);


test();

MPI_Finalize();
return 0;}
