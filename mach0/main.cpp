#include <iostream>
#include "mach0.h"


using namespace std;

int main(){

	int n=3;
	double pi = mach0(n);
	cout<<scientific << pi << endl;

	return 0;
}
