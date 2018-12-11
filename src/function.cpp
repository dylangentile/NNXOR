#include "function.h"
#include <cmath>

using namespace std;

Data::Data(){

	id = -1;
	totalNodes = 0;
	wsPerNode = 2;
	
}


Data::~Data(){



}
void
Data::setArray(int x, int y){
	nodeSet = new double[][y];



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
	for(int i = 0; i < mydata->wsPerNode; i++){
		mydata->nodeSet[mydata->id][i] = weights[i];
	}
	mydata->nodeSet[mydata->id][mydata->wsPerNode] = bias;
	mydata->nodeSet[mydata->id][mydata->wsPerNode+1] = 0;


}



void cleanup(){
	delete mydata;
}