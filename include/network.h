#pragma once
#include "function.h"



typedef struct 
{
	double value;	
} Weight;

class Network
{
public:
	Network();
	~Network();
	void initialize(int *array);
	void forwardPropagation(double *input);
	void backPropagation(double target, double rate);
	int *layout;
	int layers;
	double biasArray[5];
	double hiddenNetArray[2];
	double hiddenOutArray[2];
	double finNet, finOut;
	double *input;
	Weight k[2][2][2];
private:
};
