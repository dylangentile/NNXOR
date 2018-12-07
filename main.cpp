#include <iostream>
#include "network.h"
using namespace std;


int main(int argc, char const *argv[])
{
	int nodearray[4] = {2,2,1,-1};
	Network *myNeuralNetwork = new Network;
	myNeuralNetwork->networkInit(nodearray);












	return 0;
}