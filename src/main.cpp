#include <iostream>
//#include <fstream>
#include "network.h"
#include "function.h"
#include "trainer.h"
//#include "fadbad/fadiff.h"
//#include <cmath>
using namespace std;
/*
using namespace fadbad;

F<double> func(const F<double>& x, const F<double>& y){
	F<double> z = sqrt(x);
	return y*z+sin(z);
}


void defferent(){

	F<double> x,y,f;     // Declare variables x,y,f
	x=1;                 // Initialize variable x
	x.diff(0,2);         // Differentiate with respect to x (index 0 of 2)
	y=2;                 // Initialize variable y
	y.diff(1,2);         // Differentiate with respect to y (index 1 of 2)
	f=func(x,y);         // Evaluate function and derivatives
	double fval=f.x();   // Value of function
	double dfdx=f.d(0);  // Value of df/dx (index 0 of 2)
	double dfdy=f.d(1);  // Value of df/dy (index 1 of 2)

	cout << "\nf(x,y)=" << fval;
	cout << "\ndf/dx(x,y)=" << dfdx;
	cout << "\ndf/dy(x,y)=" << dfdy;
}
*/
int main(int argc, char const *argv[])
{

	int nodearray[4] = {2,2,1,-1}; //for now max of 3 layers.
    double *inputarray;
    inputarray = new double[nodearray[0]];
    inputarray[0] = 0.0;
    inputarray[1] = 1.0;
	Network *myNeuralNetwork = new Network;
	Trainer *myTrainer = new Trainer;
/*	
	ofstream nodecount;
	nodecount.open("../files/nodecount");
	nodecount << 0;
	nodecount.close();
*/	int zz = 0;
	while(nodearray[zz] != -1){
		zz++;
	}

	myNeuralNetwork->networkInit(nodearray);
	myNeuralNetwork->run(inputarray);
	//myTrainer->cost(inputarray,nodearray[0],myNeuralNetwork->results, nodearray[zz-1]);
	myTrainer->training();
    /*double testme = 25.0;
    std::cout << '\n' << activation((testme * activation(testme + testme)) + (testme * activation(testme + testme))) << '\n';
    //std::cout << '\n' << 4*(testme*testme) << '\n';
     
     */
	cout << "\n\nResult: "<< myNeuralNetwork->results[0] << '\n';
	//defferent();
    cleanup();
	return 0;
}

