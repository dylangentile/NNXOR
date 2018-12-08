#include "network.h"

Layer::Layer(){



}

Layer::~Layer(){



}



void
Layer::layerInit(int layerID, int mNodes, int mPrevmNodes, NodeType layerType){ //mPrevmNodes means in Layer[i-1] how many nodes are there. IE How many connections does each node have;
	myNodes = mNodes;

	nodeLayer = new Node[mNodes];
	mLayerType = layerType;
	for(int i = 0; i < mNodes; i++){
		nodeLayer[i].nodeInit(mLayerType, mPrevmNodes, i);
	}
	outputArray = new int[mNodes];
	for(int i = 0; i < mNodes; i++){
		outputArray[i] = 1;
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
	numofLayers = numofLayers - 1;
	numofInNodes = nodes[0];
	numofOutNodes = nodes[numofLayers];
	int numofHiddenNodesPerLayer[numofHiddenNodeLayers]; //ordered by layer;

	for (int i = 0; i < (numofLayers - 1); i++) //x minus 1 since x is the output layer and this counts from zero when the hidden node layers start at node layer 1;
	{
		numofHiddenNodesPerLayer[i] = nodes[i + 1];
	}
	int numofHiddenNodes;
	for (int i = 0; i < numofHiddenNodeLayers; i++)
	{
		numofHiddenNodes = numofHiddenNodes + nodes[i+1];
	}

	//int totalnodes = numofInNodes + numofHiddenNodes + numofOutNodes;

	/*
	//Various tests;
	cout << "\nTotal Nodes: " << numofInNodes + numofOutNodes + numofHiddenNodes << "\nIn: " << numofInNodes;
	cout << "\n";

	for(int i = 0; i < numofHiddenNodeLayers; i++){
		cout << "HiddenNodeLayer" << i + 1 << ": " << numofHiddenNodesPerLayer[i] << '\n'; 
	}
	cout << "Out: " << numofOutNodes << "\n\n\n";
	
	Node *testNode = new Node[totalnodes];
	for(int i = 0; i < totalnodes; i++ ){
		testNode[i].mLayer = i*i;
	}

	for(int i = 0; i <totalnodes; i++){
		testNode[i].printme();
	}
	*/
	//create iyr layers;
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
		else if (numofLayers - i == 1)
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

	}






}