#include "mach1.h"
#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

void mach1(int n, double vec1[], double vec2[])
{
	double pi=0., a=1./5., b=1./239.;
	for (int i=1; i<=n; ++i) {
		vec1[i-1]=4.0*pow(-1.0,i-1)/(2.0*i-1)*pow(a,2*i-1);
		vec2[i-1]=pow(-1.0,i-1)/(2.0*i-1)*pow(b,2*i-1);
	}
	pi=4*pi;
// This will check if vec1 and vec2 is made correctly
	ofstream myfile;
	myfile.open("vectest.txt");
	myfile << "Vector  test: \n"<<"vec1:\t "<< "vec2:\n" ;
	for(int i =0; i <n; i++){
		myfile << vec1[i] << "\t" << vec2[i] << endl;
	}
	myfile.close();
}
