#include <iostream>
#include <fstream>
#include <cmath>
#include "zeta0.h"


void vtest(int n, int s, int k){

double pi= M_PI;
std::ofstream outfile ("error.txt");

	for (int i=1; i<=k; i++){
	n= std::pow(2,i);
	double pi_n = zeta0(n,s);
	double err = std::abs(pi-pi_n);

outfile << err << "\n";
}
}
