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
private:

	NodeType mType;
	int mConnections, mNodeID;
	double *mWeights;
	double bias;
	double *outputTerms;

private:
	
};

