#include <iostream>
#include <mpi.h>
#include "reduc_zeta.h"

int main (int argc, char **argv){

MPI_Status status;

MPI_Init(&argc,&argv);
int s=2;
int n=512;

reduc_zeta(s,n);


MPI_Finalize();
return 0;}
