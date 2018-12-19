#include "network.h"
#include <iostream>
#include <math.h>







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
	for (int i = 0; i < mNodes; i++){
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

double
Layer::getNet(int x){
	return nodeLayer[x].mNet;
}

double
Layer::getAns(int x){
	return nodeLayer[x].ans;
}

double 
Layer::getWeight(int x, int whichNode){
	return nodeLayer[whichNode].fetchWeight(x);
}

void
Layer::writeWeight(double newWeight, int whichWeight, int whichNode){
	nodeLayer[whichNode].newWeight(whichWeight, newWeight);
}

int
Layer::getID(int y){
	return nodeLayer[y].mID;
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
	insNodesTotal(numofInNodes + numofOutNodes + numofHiddenNodes);

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
    results[0] = activation(results[0]);
}
void
Network::learn(double target, double learningRate){
	int nodeID = myLayers[2].getID(0);
	double weightArray[3][2] = {0};
	double theWeight = 0;
	double dE_total_dW_x = 0;
	
	for(int i = 0; i < 2; i++) //loop through output weights
	{
		theWeight = myLayers[2].getWeight(i, 0);
		dE_total_dW_x = (results[0] - target) * (results[0] *(1 - results[0])) * myLayers[1].getAns(i);
		weightArray[nodeID][i] = theWeight - (learningRate * dE_total_dW_x);
	}

	double dE_total_dOut_h1 = 0;

	for(int j = 0; j < 2; j++) //loop through nodes
	{
		nodeID = myLayers[1].getID(j);
		for(int i = 0; i < 2; i++) //loop through memeber weights
		{
			theWeight = myLayers[1].getWeight(i, j);
			dE_total_dOut_h1 = ((results[0] - target) * (results[0] *(1 - results[0]))) * getWeight(j , 0); // j is the weight that corresponds to this node's output
			dE_total_dW_x = dE_total_dOut_h1 * (myLayers[1].getAns(j) * (1 - myLayers.getAns(j))) * myLayers[0].getAns(i);
			weightArray[nodeID][i] = theWeight - (learningRate * dE_total_dW_x);
		}

	}

	int whichLayer = 1;
	int offset = -2;
	for(int j = 2; j < 5; j++)
	{
		for(int i = 0; i < 2; i++){
			myLayers[whichLayer].setWeight(weightArray[j][i], i, j - offset);
		}

		if(j == 3)
		{
			whichLayer = 2;
			offset = -4; 
		}

	}
}