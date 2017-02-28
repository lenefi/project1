#include "mach1.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "mpi.h"

using namespace std;

void mach1(int n, double* vec)
{
	
	double *vec1=vec;
	MPI_Status status;
	int rank, size, tag;
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	tag=100;
	int r=(2*n)%size; //rest to balance partitioning of array between processes
	int m=(2*n-r)/size; // least number of elements to each process
	int ind=0; //indicates how many elements already sent to processes	
	double* recvec=new double[m+1]; //Array used to receive
	int p;
	int s;
	if(rank==0){
		double pi=0., a=1./5., b=1./239.;
		for (int i=1; i<=n; ++i) {
			vec[2*(i-1)]=4.0*pow(-1.0,i-1)/(2.0*i-1)*pow(a,2*i-1);
			vec[2*(i-1)+1]=pow(-1.0,i)/(2.0*i-1)*pow(b,2*i-1); //multiply by -1 so that we can just sum up for each process
		}
		for(int i=1;i< size;i++){
			if(r>0){
				r-=1;
				p=m+1;
			}
			else{
				p=m;
			}

			vec1=vec+ind;
			MPI_Send(vec1,p,MPI_FLOAT,i,tag,MPI_COMM_WORLD);
			ind+=p;
		}
	}
	else{
		MPI_Recv(recvec, p, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, &status);
		for(int i=0; i<p;i++){
			s+=recvec[i];
		}
		cout << s << endl;	
	}	
	
/*
// This will check if vec1 and vec2 is made correctly
	ofstream myfile;
	myfile.open("vectest.txt");
	myfile << "Vector  test: \n"<<"vec1:\t "<< "vec2:\n" ;
	for(int i =0; i <n; i++){
		myfile << vec1[i] << "\t" << vec2[i] << endl;
	}
	myfile.close();

	MPI_Status status;
	char message[20];
	int rank, size, tag;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	tag=100;
	strcpy(message, "Hello world");
		for(int i=1;i< size;i++){
			MPI_Send(message,13,MPI_CHAR,i,tag,MPI_COMM_WORLD);
		}
	}
	else{
		MPI_Recv(message,13,MPI_CHAR,0, tag, MPI_COMM_WORLD,&status);
	}
	
	printf("node %d: %13s\n", rank, message);
*/
	MPI_Finalize();

}
