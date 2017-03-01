#include <iostream>
#include <fstream>
#include <cmath>
#include "zeta0.h"


int main(){

int n = 3, s = 2, k = 24;
double corr_value = (M_PI*M_PI)/6.;

std::ofstream outfile ("vtest.txt");

	for (int i=1; i<=k; i++){
	n= std::pow(2,i);
	double Sn = zeta0(n,s);
	double err = std::abs(corr_value-Sn);

outfile << err << "\n";
}
return 0;
}
