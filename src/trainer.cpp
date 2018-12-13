#include "trainer.h"
#include "function.h"
#include <cmath>
#include <iostream>
//#include "fadbad/badiff.h"
//using namespace fadbad;
Trainer::Trainer(){


	answerkey[0][0] = 0.0;
	answerkey[0][1] = 1.0;
	answerkey[1][0] = 1.0;
	answerkey[1][1] = 0.0;



}

Trainer::~Trainer(){




}
/*
B<double> error(B<double>& x, B<double>& y){

	return (((double)1.0/2.0)*(x - y)*(x - y)); // x is the expected, and y is the real


}
*/

void
Trainer::cost(double *inputs, int numberofin, double *outputs, int numberofout){
	/*B<double> ans = answerkey[(int)inputs[0]][(int)inputs[1]]; //need to work out modular input number to answer key;
	B<double> err;
	B<double> out = 0.87745;
	err = error(ans, out);*/
	






	


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