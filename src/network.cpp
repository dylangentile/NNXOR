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
}
void
Network::learn(double target, double learningRate){
	double sqError = (1.0/2.0)*((target - results[0])*(target - results[0]));
	std::cout << "\nSquared Error: " << sqError;
	//double totalError = sqError;
	//double net = myLayers[2].getNet(0);

	//std::cout << "hello";
	double dError_dOut = results[0] - target;
	double dOut_dNet = results[0] * (1 - results[0]);
	double partChain = dOut_dNet * dError_dOut;
	double dNet_dWx = 0, dError_dWx = 0;
	double myWeight = 0;
	int outNodes = 1;
	int outLayer = 2;
	int myID = 0;
    double weightArray[5][2] = {0};

	for(int z = outLayer; z > 0; z--){ //layer loop(don't want to iterate input.)
		for(int j = 0; j < outNodes; j++){ //node loop
			for (int i = 0; i < 2; i++){ //weightloop
				dNet_dWx = myLayers[z-1].getAns(i);
				myWeight = myLayers[z].getWeight(i,j); //only one node, will work on multi-node implementation.
				myID = myLayers[z].getID(j);
				dError_dWx = partChain * dNet_dWx; //finished chain rule
				myWeight = myWeight - (learningRate * dError_dWx);
				weightArray[myID][i] = myWeight;
			}
		}
		outNodes = 2;
	}
    int kk = 2;
    int ww = 2;
    for(int l = 1; l < outLayer+1; l++){
        if(l == 2){
            ww = 1;
        }
        for(int j = 0; j < ww; j++){
            for(int h = 0; h < 2; h++){
                myLayers[l].writeWeight(weightArray[kk][h], h, j);
                kk++;
            }
        }
    }
    
    
    
}



















