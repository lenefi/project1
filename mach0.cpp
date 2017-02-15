

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdio.h>


using std::cout;

double mach0(int n) {
double arctana=0, arctanb=0, a=1/5, b=1/239;
  
	for (int i=0; i<n; ++i) {
	arctana += pow(-1,i)*(pow(a,2*i+1))/(2*i+1);
	arctanb += pow(-1,i)*(pow(b,2*i+1))/(2*i+1);  }
double pi = 4*(4*arctana - arctanb);
return pi;
} 
