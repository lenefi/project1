#include "reduc_mach.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "mpi.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv)
{
	
	MPI_Init(&argc,&argv);
	if(argc<2){
		cout << "Error, program needs one arguments" <<endl;
	}
	else{
		int n=atof(argv[1]);
		double *vec=new double[2*n];
		clock_t start;
		double const corr_value =M_PI/4.;
		double *vec1=vec;
		MPI_Status status;
		int rank, size, tag;
		MPI_Comm_size(MPI_COMM_WORLD,&size);
		MPI_Comm_rank(MPI_COMM_WORLD,&rank);
		tag=100;
		int r=(2*n)%size; //rest to balance partitioning of array between processes
		int m=(2*n-r)/size; // least number of elements to each process
		double* recvec=new double[m+1]; //Array used to receive
		int p = m + (rank < r ? 1 : 0);
		double s;
		int ind=p; //indicates how many elements already sent to processes	

		double sumtest;

		if(rank==0){
			double pi=0., a=1./5., b=1./239.;
			for (int i=1; i<=n; ++i) {
				vec[2*(i-1)]=4.0*pow(-1.0,i-1)/(2.0*i-1)*pow(a,2*i-1);
				vec[2*(i-1)+1]=pow(-1.0,i)/(2.0*i-1)*pow(b,2*i-1); //multiply by -1 so that we can just sum up for each process
			}
			// set the size for root
			int const p0 = p;
			// update offset for rank 1
			for(int i=1;i< size;i++){
				if(r>0){
					r-=1;
					p=m+1;
				}
				else{
					p=m;
				}

				vec1=vec+ind;
				MPI_Send(vec1,p,MPI_DOUBLE,i,tag,MPI_COMM_WORLD);
				ind+=p;
			}
			// sum for root
			p=p0;
			recvec=vec;
		}
		else{
			MPI_Recv(recvec, p, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &status);
		}
		s=0.0;
		for(int i=0; i<p;i++){
			s+=recvec[i];
		}
		double Sn;
		MPI_Allreduce(&s, &Sn,1,MPI_DOUBLE, MPI_SUM,MPI_COMM_WORLD);

		if(rank==0){
			
			cout<< scientific << "The global sum: " <<4.0*Sn << endl;
			cout <<scientific  << "Error for n=" << n<<" and the number of processes=" <<size << ": " << abs(corr_value-Sn) << endl;
			
			double duration = (clock()-start)/(double)CLOCKS_PER_SEC;	
			cout << "Runtime: " << duration << endl;
		}
		MPI_Finalize();
	}
}
