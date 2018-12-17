#include "node.h"
#include "function.h"
#include <iostream>
#include <math.h>

Node::Node(){





}

Node::~Node(){


}



void 
Node::nodeInit(NodeType tmpType, int tmpConnections, int tmpID){
	mID = returnID();
 
	mType = tmpType;
	mConnections = tmpConnections;
	mLayerNodeID = tmpID;
	outputTerms = new double[mConnections];
     if(mConnections != 0){
        mWeights = new double[mConnections];
        for(int i = 0; i < mConnections; i++){
            mWeights[i] = (double)randomNum(99, 1) / (double)100.0;
        }
        bias = (double)randomNum(99, 1)/ (double)100.0;
    }
    else
    {
        mWeights = new double[1];
        mWeights[0] = 0;
        mWeights[1] = 0;
        bias = 0;
    }
    std::cout << mID << ": ";
    for(int i = 0; i < mConnections; i++){

    	std::cout << mWeights[i] << ", ";
	}
	std::cout << bias << '\n';

	nodeFill(mWeights, bias, mID);
}

void
Node::mInput(double in, int connNum){
	outputTerms[connNum] = in * mWeights[connNum];
}

double
Node::mOutput(){
	long double result = 0;
	for(int i = 0; i < mConnections; i++){
		result += outputTerms[i];
	}
    result += bias;
    mNet = result;
    ans = activation(result);
	return ans;

}

double
Node::fetchWeight(int x){
    return mWeights[x];
}


void 
Node::newWeight(int whichWeight, double newValue){
    long double g;
    g = std::nearbyint(newValue * 100) / 100;
    mWeights[whichWeight] = g;
}

