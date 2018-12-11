#pragma once


class Data{

public:
	Data();
	~Data();
	void setArray(int x, int y);
	int id,wsPerNode;
	double *nodeSet;
	int totalNodes;


};

double activation(long double x);
void insNodesTotal(int y);
void nodeFill(double *weights, double bias);
int returnID();
void cleanup();

