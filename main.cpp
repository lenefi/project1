

#include <iostream>
#include <cmath>


using std::cout;


double zeta(int n, int s = 2){

	double output = 0.0;
	double calc = 1.0;

	for (int i=2; i<n;i++){
	calc = 1.0/std::pow(i,s);
	output += calc;
}
return output;
}

int main(int argc, char ** argv)
{
  int n=4;
  double zSn = zeta(n, 2);
  cout << zSn << "\n";

  return 0;
}
