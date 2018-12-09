#pragma once
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
	void networkInit(int *nodes);
	void run(double *inputs);
	int layercount;
private:
	Layer *myLayers;
};