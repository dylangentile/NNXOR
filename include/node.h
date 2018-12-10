#pragma once
#include "trainer.h"

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
	friend class Trainer;
	int mID;
private:

	NodeType mType;
	int mConnections, mLayerNodeID;
	double *mWeights;
	double bias;
	double *outputTerms;

private:
	
};

