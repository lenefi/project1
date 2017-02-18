#include <iostream>
#include <cmath>
#include "mach0"

void utest(){
	expected_value=3.11;
	double pi_approx=mach0(int n=3);
	cout << "expected value Machin formula using calculator: " << expected_value << endl << "vs computed value: " << pi_approx << endl;


}
