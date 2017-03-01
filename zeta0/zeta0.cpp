#include <iostream>
#include <cmath>
#include "zeta0.h"

using std::pow;
using std::sqrt;

double zeta0(int n, int s){

	double output = 0.0;
	double calc;

	for (int i=1; i<=n;i++){
	calc = 1.0/pow(i,s);
	output += calc;
}

return output;
}
