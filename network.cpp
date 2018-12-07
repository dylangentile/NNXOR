#include "network.h"
#include <iostream>

using namespace std;

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

	cout << "\nTotal Nodes: " << numofInNodes + numofOutNodes + numofHiddenNodes << "\nIn: " << numofInNodes;
	cout << "\n";

	for(int i = 0; i < numofHiddenNodeLayers; i++){
		cout << "HiddenNodeLayer" << i + 1 << ": " << numofHiddenNodesPerLayer[i] << '\n'; 
	}
	cout << "Out: " << numofOutNodes << '\n';

}