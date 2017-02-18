#include <iostream>
#include <cmath>
#include "mach0.h"
#include "utest.h"

using namespace std;

void utest(){
	double expected_value=3.11;
	int n=3;
	double pi_approx=mach0(n);
	cout << "expected value Machin formula using calculator: " << expected_value << endl << "vs computed value: " << pi_approx << endl;
}
