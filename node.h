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

private:

	NodeType mType;
	int mConnections, mNodeID;
	int *mWeights;
	int bias;

private:
	
};

