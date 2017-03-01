#include <iostream>
#include <cmath>
#include "zeta0.h"

int main(){
double corr_value = (M_PI*M_PI)/6.;
int n = 3, s = 2;

double Sz=zeta0(n,s);

std::cout <<"N=" << n <<"\n";
std::cout << "Error = " << corr_value - Sz << "\n";

return 0;
}



