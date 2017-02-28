#include <iostream>
#include <mpi.h>
#include "zeta1.h"

int main (int argc, char **argv){

MPI_Status status;

MPI_Init(&argc,&argv);
int s=2;
int n=16;

//test();
zeta1(s,n);


MPI_Finalize();
return 0;}
