#include <iostream>
#include <cmath>
#include "mpi.h"
#include <ctime>
#include "reduc.h"

clock_t start = clock();


void reduc(int s, int n){

double corr_value = (M_PI*M_PI)/6.;

int size, rank,i;

MPI_Status status;
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

int tag = 100;
int r= n%size;
int m = (n-r)/size;
double pvec[m];

if (rank ==0) {
        double vec[n];
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
	for (i=0; i<m; i++ ){
		part_sum += pvec[i];
	}
	double Sn;
 	MPI_Allreduce(&part_sum,&Sn, 1, MPI_DOUBLE, MPI_SUM,MPI_COMM_WORLD);
	clock_t end_all = clock();
	double sigma(part_sum), sigma_q;
	int p(rank), P(size);
	
	for (int d = 0; d <std::log2(P); d++){
	int q=(p^(1<<d));
	MPI_Send(&sigma,1,MPI_DOUBLE,q ,tag,MPI_COMM_WORLD);
	MPI_Recv(&sigma_q,1, MPI_DOUBLE,q ,tag,MPI_COMM_WORLD, &status);
	sigma +=sigma_q;
	}
clock_t end_comp = clock();





std::cout << "Difference of value: " << corr_value -Sn << '\n';
clock_t end = clock();
float seconds = (float)((end_comp - start)-(end_all-start)) / CLOCKS_PER_SEC;

std::cout << "Difference of t: " << seconds << " seconds." << '\n'; }
