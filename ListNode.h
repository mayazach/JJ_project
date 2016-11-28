#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include <stdint.h> 


using namespace std;


class list_node
{
	uint32_t* neighbor;
	uint32_t* edgeProperty;
	int nextListNode;
	int noOfneighbors;
	int size;

public:

	list_node() :neighbor(NULL), edgeProperty(NULL), nextListNode(0) {}

	list_node(const int _noOfneigbors)
	{
		neighbor = new uint32_t[_noOfneigbors];
	//	edgeProperty = new uint32_t[_noOfneigbors];

		if (neighbor == NULL) //|| edgeProperty == NULL)
		{
			cerr << "list_node: Memory allocation error." << endl;
		}
		nextListNode = 0;
		noOfneighbors = 0;
		size = _noOfneigbors;
	}

	int getNextListNode()
	{
		return nextListNode;
	}

	void setNext(int next)
	{
		nextListNode = next;
	}


	uint32_t* getNeighbor()
	{
		return neighbor;
	}

	int getNoOfNeighbors()
	{
		return noOfneighbors;
	}

	bool isFull()
	{
		if (noOfneighbors >= size)
		{
			return true;
		}
		return false;
	}


	int addNeighbor(uint32_t newNeighbor)
	{
		neighbor[noOfneighbors] = newNeighbor;
		noOfneighbors++;
		return EXIT_SUCCESS;
	}


	~list_node()
	{
		delete[] neighbor;
	//	delete[] edgeProperty;
	}


};


#endif
