

#include <iostream>
#include <cmath>


using std::cout;
using std::pow;
using std::sqrt;

double zeta(int n, int s = 2){

	double output = 0.0;
	double calc;

	for (int i=1; i<=n;i++){
	calc = 1.0/pow(i,s);
	output += calc;
cout <<i << "gives computed value " <<sqrt(6*output)<<"\n";
cout << "expected value: 3.14" <<"\n";
}
output=std::sqrt(6* output);
return output;
}




double mach0(int n) {
   double pi=0., a=1./5., b=1./239.;
 
	for (int i=1; i<=n; ++i) {
	pi+= (double)pow(-1,i-1)/(double)(2*i-1)*(4*pow(a,2*i-1)-1*pow(b,2*i-1)); 
 cout <<i << " gives computed value " <<4*pi<<"\n";
cout << "expected value: 3.14" <<"\n";
}
pi=4*pi;
return pi;
}
  


int main(int argc, char ** argv)
{
 int n=3;
  double zSn =  zeta(n, 2);
  double mSn = mach0(n);
  cout <<"pi_z=" <<zSn << "\n";
  cout <<"pi_m=" <<mSn << "\n";


  return 0;

} 
