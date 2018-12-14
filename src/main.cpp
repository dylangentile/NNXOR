#include <iostream>
#include "network.h"
#include "function.h"
using namespace std;

int main(int argc, char const *argv[])
{

	int nodearray[4] = {2,2,1,-1}; //for now max of 3 layers.
    double *inputarray;
    inputarray = new double[nodearray[0]];
    inputarray[0] = 0.0;
    inputarray[1] = 1.0;
	Network *myNeuralNetwork = new Network;
	
	int zz = 0;
	while(nodearray[zz] != -1){
		zz++;
	}

	myNeuralNetwork->networkInit(nodearray);
	myNeuralNetwork->run(inputarray);
   
     
     
	cout << "\n\nResult: "<< myNeuralNetwork->results[0] << '\n';
    cleanup();
	return 0;
}

