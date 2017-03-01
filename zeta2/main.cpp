#include <iostream>
#include <mpi.h>
#include <omp.h>
#include "zeta2.h"

int main (int argc, char **argv){

MPI_Status status;

MPI_Init(&argc,&argv);
int s=2;
int n=512;


zeta2(s,n);


MPI_Finalize();
return 0;}
