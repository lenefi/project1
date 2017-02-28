#include <iostream>
#include <cmath>
#include "mpi.h"
#include <ctime>
#include "zeta1.h"

clock_t start = clock();


void zeta1(int s, int n){

int size, rank,i;
double vec[n];

MPI_Status status;
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

int tag = 100;
int r= n%size;
int m = (n-r)/size;

if (rank ==0) {
	for (i=1; i<n; i++){
	double start = 1.0/std::pow(i,s);
	vec[i-1]= start;
	}

	for (i=1; i<size; i++){

	MPI_Send(&vec[(i-1)*m],m,MPI_DOUBLE,i,tag,MPI_COMM_WORLD);}}
		
else{
	MPI_Recv(&vec,m, MPI_DOUBLE,0,tag,MPI_COMM_WORLD, &status);

std::cout << "node " << i << ": "<< vec << '\n';
 	MPI_Reduce(vec,vec, m, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD );

}

std::cout << "Pi tilnærmet: " << *vec << '\n';

clock_t end = clock();
float seconds = (float)(end - start) / CLOCKS_PER_SEC;

std::cout << "It took " << seconds << " seconds." << '\n'; }
