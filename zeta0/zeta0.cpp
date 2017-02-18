#include <iostream>
#include <cmath>
#include "zeta0.h"

using std::cout;
using std::pow;
using std::sqrt;

double zeta(int n, int s = 2){

	double output = 0.0;
	double calc;

	for (int i=1; i<=n;i++){
	calc = 1.0/pow(i,s);
	output += calc;
}
output=std::sqrt(6* output);
return output;
}
