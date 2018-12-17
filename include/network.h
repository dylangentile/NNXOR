#pragma once
#include "function.h"
#include "node.h"


class Layer
{
public:
	Layer();
	~Layer();
	void layerInit(int layerID, int mNodes, int mPrevmNodes, NodeType layerType);
	void input(double *inputs);
	int myNodes;
	double *output();
	double getNet(int x);
	double getAns(int x);
	double getWeight(int x, int whichNode);
	void writeWeight(double newWeight, int whichWeight, int whichNode);
private:
	NodeType mLayerType;
	double *outputArray;
	Node *nodeLayer;
	int prevNodes;

}; 


class Network
{
public:
	Network();
	~Network();
	double *results;
	void networkInit(int *nodes);
	void run(double *inputs);
	void learn(double target, double learningRate);
	int layercount;
private:
	Layer *myLayers;
};