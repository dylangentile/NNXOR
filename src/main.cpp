#include <iostream>
#include "network.h"
#include "function.h"
using namespace std;


int main(int argc, char const *argv[])
{
	int nodearray[4] = {2,2,1,-1}; //for now max of 3 layers.
    double *inputarray;
    inputarray = new double[nodearray[0]];
    inputarray[0] = 1.0;
    inputarray[1] = 1.0;
	Network *myNeuralNetwork = new Network;
	myNeuralNetwork->networkInit(nodearray);
	myNeuralNetwork->run(inputarray);
    /*double testme = 25.0;
    std::cout << '\n' << activation((testme * activation(testme + testme)) + (testme * activation(testme + testme))) << '\n';
    //std::cout << '\n' << 4*(testme*testme) << '\n';
     
     */
	return 0;
}
