#include "mach1.h"
#include "mpi.h"
#include <cmath>
int main(int argc,char **argv)
{
	int n =pow(2, 15);
	double *vec=new double[2*n];
	MPI_Init(&argc, &argv);
	mach1(n,vec);
	return 0;
}
