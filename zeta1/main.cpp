#include <iostream>
#include <mpi.h>
#include "zeta1.h"
#include <fstream>
#include <cmath>

int main (int argc, char **argv){
std::ofstream data ("data.txt");


double error, tid;
int s=2;
MPI_Init(&argc,&argv);

data << "n: " <<"\t"<< "Error: "<<"\t"<<"tid: " << "\n";
for (int k=1; k<16; k++){

int n;
n=std::pow(2,k);


zeta1(s,n);

data << n << "\n";
}

MPI_Finalize();
return 0;}
