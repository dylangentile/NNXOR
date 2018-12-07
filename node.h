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
	int mlayer;
	NodeType myType;
	int myConnections;
	


private:




private:
	
};

