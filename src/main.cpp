#include <iostream>
#include "network.h"
#include "function.h"
#include "trainer.h"

using namespace std;

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

