#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include <string>
#include <stdint.h> 



class list_node {
	uint32_t* neighbor; //the ids of the neighbor nodes
	uint32_t* edgeProperty; //property for each edge
	list_node* nextListNode; //
	uint32_t size;
	uint32_t noOfneigbors;

public:
	list_node(const int n)
	{
		neighbor = new uint32_t(n);
		edgeProperty = new uint32_t(n);
		nextListNode = NULL;
		noOfneigbors = 0;
		size = n;
	}

	~list_node()
	{
		delete neighbor;
		delete edgeProperty;
		list_node* temp = nextListNode;
		while (nextListNode != NULL)
		{
			temp = nextListNode->nextListNode;
			delete nextListNode;
			nextListNode = temp;
		}
	}

	list_node* getNextListNode()
	{
		return nextListNode;
	}

	void setNext(list_node* next)
	{
		nextListNode = next;
	}
	bool isFull()
	{
		if (noOfneigbors >= size)
		{
			return true;
		}
		return false;
	}
	int addNeighbor(uint32_t nodeId)
	{
		neighbor[noOfneigbors] = nodeId;
		noOfneigbors++;
		return EXIT_SUCCESS;
	}

	uint32_t* getNeighbor(){
		return neighbor; 
	}

	int getNoOfNeighbors(){
		return noOfneigbors;
	}
};

#endif


