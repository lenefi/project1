#include "mach1.h"
#include "mpi.h"

int main(int argc,char **argv)
{
	int n =4;
	double *vec=new double[2*n];
	MPI_Init(&argc, &argv);
	mach1(n,vec);
	return 0;
}
