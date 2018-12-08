#include "node.h"
#include <cstdlib>
#include <iostream>

Node::Node(){



}

Node::~Node(){


}



void 
Node::nodeInit(NodeType tmpType, int tmpConnections, int tmpID){
	mType = tmpType;
	mConnections = tmpConnections;
	mNodeID = tmpID;

	mWeights = new int[mConnections];
	for(int i = 0; i < mConnections; i++){
		mWeights[i] = std::rand() % 97 + 2;
		std::cout << mWeights[i];
		std::cout << '\n'; 
	}
	bias = std::rand() % 99 + 1;
}
