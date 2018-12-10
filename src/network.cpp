#include "network.h"
#include <iostream>

Layer::Layer(){



}

Layer::~Layer(){



}



void
Layer::layerInit(int layerID, int mNodes, int mPrevmNodes, NodeType layerType){ //mPrevmNodes means in Layer[i-1] how many nodes are there. IE How many connections does each node have;
	myNodes = mNodes;
	prevNodes = mPrevmNodes;
	nodeLayer = new Node[mNodes];
	mLayerType = layerType;
	for(int i = 0; i < mNodes; i++){
		nodeLayer[i].nodeInit(mLayerType, prevNodes, i);
	}
	outputArray = new double[mNodes];
	for(int i = 0; i < mNodes; i++){
		outputArray[i] = 1;
	}
}

void
Layer::input(double *inputs){
	if(mLayerType == mNode_INPUT){
		for(int j = 0; j < myNodes; j++)
		{
			outputArray[j] = inputs[j]; // in theory we should be reading from the node output function but that step is skipped since these are the input nodes.
			nodeLayer[j].mInput(inputs[j], 1);
		}
	} 
	else
	{
		for (int i = 0; i < myNodes; i++)
		{
			for(int j = 0; j < prevNodes; j++)
			{
				nodeLayer[i].mInput(inputs[j], j);
			}
		}
	}
}

double 
*Layer::output(){
	if(mLayerType == mNode_INPUT){
		return outputArray; //overides whatever data is stored.
	} 
	else
	{
		for(int i = 0; i < myNodes; i++){
			outputArray[i] = nodeLayer[i].mOutput();
		}
		return outputArray;
	}	
}


Network::Network(){



}

Network::~Network(){



}


void
Network::networkInit(int *nodes){ //in order for this to work a 4 value array must be inputted (including the -1)
	int numofLayers = 0; //number of layers; counting from zero; of course
	int numofHiddenNodeLayers = 0;
	int numofInNodes = 0;
	int numofOutNodes = 0;
	while (nodes[numofLayers] != -1)
	{
		if(numofLayers != 0 && nodes[numofLayers + 1] != -1)
		{
			numofHiddenNodeLayers++;
		}
		numofLayers++;

	}

	numofInNodes = nodes[0];
	numofOutNodes = nodes[numofLayers - 1];
	int numofHiddenNodesPerLayer[numofHiddenNodeLayers]; //ordered by layer;

	for (int i = 0; i < numofHiddenNodeLayers; i++)
	{
        numofHiddenNodesPerLayer[i] = nodes[i + 1]; //plus one since we're counting from 0 hidden layers but the first hidden layer is nodes[1] not nodes[0];
	}
	int numofHiddenNodes;
	for (int i = 0; i < numofHiddenNodeLayers; i++)
	{
		numofHiddenNodes = numofHiddenNodes + nodes[i+1];
	}

	//create the layers;
	myLayers = new Layer[numofLayers];
	NodeType lLayerType;
	int fillNodes;
	int prevnodes;
	for (int i = 0; i < numofLayers; i++)
	{


		if(i == 0)
		{
			lLayerType = mNode_INPUT;
			fillNodes = numofInNodes;
		}
		else if (numofLayers-1 == i)
		{
			lLayerType = mNode_OUTPUT;
			fillNodes = numofOutNodes;
		}
		else 
		{
			lLayerType = mNode_HIDDEN;
			fillNodes = numofHiddenNodesPerLayer[i-1];

		}

		if(i == 0){
			prevnodes = 0;
		} else {
			prevnodes = myLayers[i-1].myNodes;
		}


		myLayers[i].layerInit(i, fillNodes, prevnodes, lLayerType);
		layercount = numofLayers;

	}
}

void
Network::run(double *inputs){
	double *outputs = inputs;
    int i;
	for(i = 0; i < layercount - 1; i++){
		myLayers[i].input(outputs);
		outputs = myLayers[i].output();
	}
    myLayers[i].input(outputs);
    results = myLayers[i].output();
}
void
Network::learn(){




}



















