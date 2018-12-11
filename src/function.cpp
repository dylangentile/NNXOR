#include "function.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>   

using namespace std;

unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

Data::Data(){

	id = -1;
	totalNodes = 0;
	wsPerNode = 2;
	seed = mix(clock(), time(NULL), getpid());
	srand(seed);
}
unsigned long
Data::rnd(){
	return rand();
}

Data::~Data(){



}
void
Data::setArray(int x, int y){
	//nodeSet = new double[][y];



}

Data *mydata = new Data;

double activation(long double x){
	long double y;
	double ans;
	y = (M_1_PI * (atan(x - 50.0))) + 0.5;
	//y = 1/(1+exp(-1*x));
	ans = y;
	return ans;
}



int returnID(){
	mydata->id++;
	return mydata->id;	


}

void insNodesTotal(int y){
	mydata->totalNodes = y;
	int alloc = mydata->wsPerNode + 2;
	mydata->setArray(y, alloc);

}


void nodeFill(double *weights, double bias){
	/*for(int i = 0; i < mydata->wsPerNode; i++){
		mydata->nodeSet[mydata->id][i] = weights[i];
	}
	mydata->nodeSet[mydata->id][mydata->wsPerNode] = bias;
	mydata->nodeSet[mydata->id][mydata->wsPerNode+1] = 0;
*/

}

unsigned long randomNum(int x, int y){
	return mydata->rnd() % x + y;
}

void cleanup(){
	delete mydata;
}