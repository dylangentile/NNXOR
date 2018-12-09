#include "node.h"
#include "function.h"
#include <random>



Node::Node(){

}

Node::~Node(){


}



void 
Node::nodeInit(NodeType tmpType, int tmpConnections, int tmpID){
	mType = tmpType;
	mConnections = tmpConnections;
	mNodeID = tmpID;
	outputTerms = new double[mConnections];
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(2,99);
	//std::srand(time(NULL));
    if(mConnections != 0){
        mWeights = new double[mConnections];
        for(int i = 0; i < mConnections; i++){
            mWeights[i] = dist6(rng);
        }
        bias = dist6(rng);
    }
    else
    {
        mWeights = new double[1];
        mWeights[0] = 0;
        bias = 0;
    }
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
