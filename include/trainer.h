#pragma once
#include "node.h"
#include "function.h"
class Trainer{

public:
	Trainer();
	~Trainer();
	void training();
	void cost(double *inputs, int numberofin, double *outputs, int numberofout);

	double answerkey[2][2];




};


