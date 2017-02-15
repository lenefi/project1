

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdio.h>


using std::cout;

int s=2;
double n=4;

double zeta(double n){

	double output = 0.0;
	double calc = 1.0;

	for (int i=2; i<n;i++){
	output += calc;
	calc = 1.0/pow(i,s);
}
return output;
cout << calc << "\n";
}
