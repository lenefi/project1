#include <iostream>
#include <mpi.h>
#include "zeta1.h"
#include <fstream>
#include <cmath>

int main (int argc, char **argv){
std::ofstream data ("data.txt");

int s=2;
//int n=512;


double *error;
double *tid;

data <<"n: "<<"\t"<< "Error: "<<"\t"<<"tid: " << "\n";
for (int k=1; k<30; k++){

int n;
n=std::pow(2,k);


zeta1(s,n, error, tid, argc, argv);

data <<n<<"\t"<< &error<<"\t"<<&tid << "\n";
}


return 0;}
