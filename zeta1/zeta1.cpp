#include <iostream>
#include <cmath>
#include "mpi.h"
<<<<<<< HEAD
#include <ctime>

clock_t start = clock();


void zeta1(int s, int n){

=======

void zeta1(int s, int n){

>>>>>>> da2c7dcfdcc5db9394532f3a9729b6442ece6f6e

int size, rank,i;
int vec[n];

MPI_Status status;
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

int tag = 100;
int r= n%size;
int m = (n-r)/size;

if (rank ==0) {

<<<<<<< HEAD
	for (i=1; i<n; i++){
	double start = 1.0/std::pow(i,s);
	vec[i-1]= start;
	}

	for (i=1; i<size; i++){

	MPI_Send(&vec[(i-1)*m],m,MPI_DOUBLE,i,tag,MPI_COMM_WORLD);}}
		
else{
	MPI_Recv(&vec,m, MPI_DOUBLE,0,tag,MPI_COMM_WORLD, &status);
	double pi[size];
	for (i=1; i<n; i++){
	pi[i]=std::sum(vec);

	MPI_Send(pi, size, MPI_DOUBLE, 0,tag, MPI_COMM_WORLD);
	MPI_Recv(pi, size, MPI_DOUBLE, i,tag, MPI_COMM_WORLD, &status);
	}
=======
	for (i=1; i<=n; i++){
	double start = 1.0/std::pow(i,s);
	vec[i-1]= start;
	}
>>>>>>> da2c7dcfdcc5db9394532f3a9729b6442ece6f6e

	for (i=1; i<=size; i++){
	int vec_temp[m];
	vec_temp = vec[(i-1*m):i*m-1];
	MPI_Send(vec_temp,n,MPI_DOUBLE,i,tag,MPI_COMM_WORLD);}}
		
else{
	MPI_Recv(vec_temp,n, MPI_DOUBLE,0,tag,MPI_COMM_WORLD, &status);}

 }

	

}

}

clock_t end = clock();
float seconds = (float)(end - start) / CLOCKS_PER_SEC;

