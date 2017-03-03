#include <iostream>
#include <cmath>
#include "mpi.h"
#include "omp.h"
#include <ctime>
#include "zeta1.h"
#include <fstream>

clock_t start = clock();


void zeta1(int s, int n, double *error, double *tid, int argc, char **argv){


double corr_value = (M_PI*M_PI)/6.;

int size, rank,i;
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

int tag = 100;
int r= n%size;
int m = (n-r)/size;
double pvec[m];

if (rank ==0) {
        double vec[n];

	#pragma omp parallel for
	for (i=1; i<=n; i++){
	double start = 1.0/std::pow(i,s);
	vec[i-1]= start;
	}
        for (i=0; i<m; i++){
        pvec[i]=vec[i];
	}
	for (i=1; i<size; i++){

	MPI_Send(&vec[i*m],m,MPI_DOUBLE,i,tag,MPI_COMM_WORLD);}}
		
else{
	MPI_Recv(pvec,m, MPI_DOUBLE,0,tag,MPI_COMM_WORLD, &status);

}



	double part_sum = 0.;
	#pragma omp parallel for reduction(+:part_sum)
	for (i=0; i<m; i++ ){
		part_sum += pvec[i];
}
	double Sn;
 	MPI_Reduce(&part_sum,&Sn, 1, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);

if(rank == 0)
{


std::cout << "Error of correct value and estimated value: " << corr_value -Sn << '\n';
clock_t end = clock();
double seconds = (double)(end - start) / CLOCKS_PER_SEC;
*error=std::abs(corr_value-Sn);
*tid=seconds;
std::cout << "It took " << seconds << " seconds." << '\n'; }
MPI_Finalize();
}
