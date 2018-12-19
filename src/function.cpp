#include "function.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
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
    //return 5;
}

Data::~Data(){



}
void
Data::setArray(){


}

Data *mydata = new Data;

double activation(long double x){
	long double y;
	double ans;
	//y = (M_1_PI * (atan(x/*- 50.0*/))) + 0.5;
	y = (double)1/((double)1+(double)exp((double)-1*x));
	ans = y;
	return ans;
}



int returnID(){
	mydata->id++;
	return mydata->id;	


}

void insNodesTotal(int y){
	mydata->totalNodes = y;
	//int alloc = mydata->wsPerNode + 2;
	mydata->setArray();

}


void nodeFill(double *weights, double bias, int nodeId){
	/*for(int i = 0; i < mydata->wsPerNode; i++){
		mydata->nodeSet[mydata->id][i] = weights[i];
	}
	mydata->nodeSet[mydata->id][mydata->wsPerNode] = bias;
	mydata->nodeSet[mydata->id][mydata->wsPerNode+1] = 0;
*/
	mydata->setArray();
	for(int i = 0; i < 2; i++){
		mydata->nodeSet[nodeId][i] = weights[i];
	}
	mydata->nodeSet[nodeId][2] = bias;

}

unsigned long randomNum(int x, int y){
	return mydata->rnd() % x + y;
}

Data*
getNodeInfo(){
	return mydata;
}


void cleanup(){
	delete mydata;
}
