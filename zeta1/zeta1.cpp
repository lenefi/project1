#include <iostream>
#include "mpi.h"
#include <cstring>

void zeta1(int s)

int size, rank,i;

MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

tag = 100;

if (rank ==0) {

	for (i=1; i<size; i++){
	double start = 1.0/pow(i,s);
	MPI_Send(start,1,MPI_DOUBLE,i,tag,MPI_COMM_WORLD);}}
else{
	MPI_Recv(start,1, MPI_DOUBLE,0,tag,MPI_COMM_WORLD, &status);
}

std::cout << "node: "<< rank  <<  message << "\n";


}
