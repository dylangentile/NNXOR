#include "trainer.h"
#include "function.h"
#include <cmath>
#include <iostream>
Trainer::Trainer(){


	answerkey[0][0] = 0.0;
	answerkey[0][1] = 1.0;
	answerkey[1][0] = 1.0;
	answerkey[1][1] = 0.0;



}

Trainer::~Trainer(){




}




void
Trainer::cost(double *inputs, int numberofin, double *outputs, int numberofout){
	double *dcost_dpred = new double[2];
	int ans = answerkey[(int)inputs[0]][(int)inputs[1]]; //need to work out modular input number to answer key;
	float cost;
	{ //extra brackets to delete the i variable.
	int i;
	for (i = 0; i < numberofout; i++){
		cost += std::pow((outputs[i] - ans), 2); //this is wrong...
	}
	cost = cost * (1/i);
	}
	//std::cout << '\n' <<cost << '\n';
	for(int i = 0; i < numberofout; i++){
		dcost_dpred[i] = 2*(outputs[i] - ans);
	}

	


}

void
Trainer::training(){
	Data *dataArray = getNodeInfo();

	for (int j = 0; j < 5; j++){
		std::cout << '\n' << j << ": ";
		int i = 0;
		for(i = 0; i < 2; i++){
			std::cout << dataArray->nodeSet[j][i] << ", ";
		}
		std::cout << dataArray->nodeSet[j][i];
	}
	

}