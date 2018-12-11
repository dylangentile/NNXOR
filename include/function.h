#pragma once


class Data{

public:
	Data();
	~Data();
	void setArray();
	int id,wsPerNode;
	double nodeSet[5][3];
	int totalNodes;
	unsigned long seed;
	unsigned long rnd();
private:
	
};


unsigned long randomNum(int x, int y);

Data *getNodeInfo();

double activation(long double x);
void insNodesTotal(int y);
void nodeFill(double *weights, double bias, int nodeId);
int returnID();
void cleanup();


