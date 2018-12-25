#pragma once

typedef enum
{
	mNode_INPUT,
	mNode_OUTPUT,
	mNode_HIDDEN


} NodeType;



class Node
{


public:
	Node();
	~Node();	
	void nodeInit(NodeType tmpType, int tmpConnections, int tmpID);
	void mInput(double in, int conns);
	double mOutput();
	int mID;
	double mNet, ans;
	double fetchWeight(int x);
	void newWeight(int whichWeight, double newValue);
	double fetchBias();
private:

	NodeType mType;
	int mConnections, mLayerNodeID;
	double *mWeights;
	double bias;
	double *outputTerms;

private:
	
};

