#include "node.h"
#include <random>
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
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(2,99);
	//std::srand(time(NULL));
    if(mConnections != 0){
        mWeights = new int[mConnections];
        for(int i = 0; i < mConnections; i++){
            mWeights[i] = dist6(rng);
        }
        bias = std::rand() % 99 + 1;
    }
    else
    {
        mWeights = new int[1];
        mWeights[0] = 0;
        bias = 0;
    }
    int x = mWeights[0];
    std::cout << x;
    std::cout << '\n';
}
