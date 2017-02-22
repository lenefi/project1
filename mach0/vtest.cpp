#include <iostream>
#include <cmath>
#include <fstream>
#include "vtest.h"
#include "mach0.h"
using namespace std;

void vtest(){
	ofstream myfile;
	myfile.open("vtest.txt");
	myfile << "Verification test: \n";
	double error, pi_approx;
	int n;
	for(int i = 1; i <25; i++){
		n=pow(2,i);
		pi_approx=mach0(n);
		error=abs(M_PI-pi_approx);
		myfile <<scientific<< "Error for n=" << n << ": " << error << endl;
	}
	myfile.close();
}
