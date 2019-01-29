#include "network.h"
#include "function.h"
#include <iostream>
#include <fstream>


Network::Network(){

}

Network::~Network(){

}

void
Network::initialize(int *array){
	layout = new int[4];
	layout[0] = 2;
	layout[1] = 2;
	layout[2] = 1;
	layout[3] =-1;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int q = 0; q < 2; q++){
				k[i][j][q].value = (double)randomNum(99, 1) / (double)100.0;
			}
		}
	}

	for(int i = 0; i < 5; i++){
		biasArray[i] = (double)randomNum(99, 1) / (double)100.0;
	}
}

void
Network::forwardPropagation(double *inputs){
	input = inputs;
	hiddenNetArray[0] = (k[0][0][0].value * input[0])+(k[0][0][1].value * input[1]) + biasArray[2];
	hiddenNetArray[1] = (k[0][1][0].value * input[0])+(k[0][1][1].value * input[1]) + biasArray[3];

	for (int i = 0; i < 2; i++){
		hiddenOutArray[i] = activation(hiddenNetArray[i]);
	}

	finNet = (k[1][0][0].value * hiddenOutArray[0]) + (k[1][0][1].value * hiddenOutArray[1]) + biasArray[4];
	finOut = activation(finNet);
}

void
Network::backPropagation(double target, double rate){
	Weight stagedWeights[2][2][2];
	double stagedBiases[5];

	//two output weights
	double change = dActivation(finNet) * hiddenOutArray[0] * 2 * (finOut - target);
	stagedWeights[1][0][0].value = k[1][0][0].value - (rate * change);

	change = dActivation(finNet) * hiddenOutArray[1] * 2 * (finOut - target);
	stagedWeights[1][0][1].value = k[1][0][1].value - (rate * change);

	//output bias
	double dC_db = dActivation(finNet) * 2 * (finOut - target);
	stagedBiases[4] = biasArray[4] - (rate * dC_db);

	//hidden weights for neuron 0;

	double pd = k[1][0][0].value * dC_db * dActivation(hiddenNetArray[0]);
	change = pd * input[0];
	stagedWeights[0][0][0].value = k[0][0][0].value - (rate * change);

	change = pd * input[1];
	stagedWeights[0][0][1].value = k[0][0][1].value - (rate * change);

	stagedBiases[2] = biasArray[2] - (dC_db * dActivation(hiddenNetArray[0]) * rate);

	//hiddenWeights for neuron 1;

	pd = k[1][0][1].value * dC_db  * dActivation(hiddenNetArray[1]);
	
	change = pd * input[0];
	stagedWeights[0][1][0].value = k[0][1][0].value - (rate * change);

	change = pd * input[1];
	stagedWeights[0][1][1].value = k[0][1][1].value - (rate * change);

	stagedBiases[3] = biasArray[3] - ((dC_db * dActivation(hiddenNetArray[1])) * rate);




	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int w = 0; w < 2; w++){
				k[i][j][w].value = stagedWeights[i][j][w].value;
			}
		}
	}

	for(int i = 0; i < 5; i++){
		biasArray[i] = stagedBiases[i];
	}

}