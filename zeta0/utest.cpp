#include <iostream>
#include <cmath>
#include "zeta0.h"

void utest(int n, int s){

double Sz=zeta0(n,s);

std::cout <<"N=" << n << "=" <<Sz<<"\n";
std::cout << "Copmuted value = 2.85773803" <<"\n";

}


