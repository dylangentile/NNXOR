#include "node.h"
#include "function.h"
#include <iostream>



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
    /*
    //unix method
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(2,99);
    int random = dist6();
	*/
        if(mConnections != 0){
        mWeights = new double[mConnections];
        for(int i = 0; i < mConnections; i++){
            mWeights[i] = randomNum(99, 1);
        }
        bias = randomNum(99, 1);
    }
    else
    {
        mWeights = new double[1];
        mWeights[0] = 0;
        bias = 0;
    }
    std::cout << mID << ": ";
    for(int i = 0; i < mConnections; i++){

    	std::cout << mWeights[i] << ", ";
	}
	std::cout << '\n';

	nodeFill(mWeights, bias);
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
    double ans = activation(result);
	return ans;

}
