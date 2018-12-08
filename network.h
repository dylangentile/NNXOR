#pragma once
#include "node.h"

class Layer
{
public:
	Layer();
	~Layer();
	void layerInit(int layerID, int mNodes, int mPrevmNodes, NodeType layerType);
	int myNodes;
private:
	NodeType mLayerType;
	int *outputArray;
	Node *nodeLayer;

}; 


class Network
{
public:
	Network();
	~Network();
	void networkInit(int *nodes);

private:
	Layer *myLayers;
};