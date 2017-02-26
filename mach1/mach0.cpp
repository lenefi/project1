#include "mach0.h"
#include <cmath>

double mach0(int n) {
	double pi=0., a=1./5., b=1./239.;
	for (int i=1; i<=n; ++i) {
		pi+= (double)pow(-1,i-1)/(double)(2*i-1)*(4*pow(a,2*i-1)-1*pow(b,2*i-1));
	}
	pi=4*pi;
	return pi;
}
