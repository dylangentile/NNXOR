#include "function.h"
#include <cmath>

using namespace std;

double activation(long double x){
	long double y;
	double ans;
	//y = (M_1_PI * (atan(x - 50.0))) + 0.5;
	y = 1/(1+exp(-1*x))
	ans = y;
	return ans;
}
