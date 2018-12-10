#pragma once
#include "node.h"

class Trainer{

public:
	Trainer();
	~Trainer();
	void train();
	void cost(double *inputs, int numberofin, double *outputs, int numberofout);

	double answerkey[2][2];




};


