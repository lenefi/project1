#include <iostream>
#include <cmath>
#include "mpi.h"

void zeta1(int s, int n){


int size, rank,i;
int vec[n];

MPI_Status status;
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

int tag = 100;
int r= n%size;
int m = (n-r)/size;

if (rank ==0) {

	for (i=1; i<=n; i++){
	double start = 1.0/std::pow(i,s);
	vec[i-1]= start;
	}

	for (i=1; i<=size; i++){
	int vec_temp[m];
	vec_temp = vec[(i-1*m):i*m-1];
	MPI_Send(vec_temp,n,MPI_DOUBLE,i,tag,MPI_COMM_WORLD);}}
		
else{
	MPI_Recv(vec_temp,n, MPI_DOUBLE,0,tag,MPI_COMM_WORLD, &status);}

}
