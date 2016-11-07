#ifndef NODEINDEX_H
#define NODEINDEX_H
#include <iostream>
#include <string>
#include "Ptr.h"
#include "Buffer.h"
using namespace std;

class NodeIndex

{
	Ptr** nodeIndex;
	uint32_t size;
	uint32_t noOfNeighbors;


public:
	NodeIndex(const uint32_t n, uint32_t _noOfNeighbors)
	{
		nodeIndex = new Ptr*[n];

		if (nodeIndex == NULL)
		{
			cerr << "NodeIndex: Memory allocation error." << endl;
		}

		memset(nodeIndex, NULL, sizeof(hashNode*) * n);
		size = n;
		noOfNeighbors = _noOfNeighbors;
	}

	//NodeIndex* createNodeIndex();

	uint32_t getSize()
	{
		return size;
	}


	void setSize(uint32_t newSize)
	{
		size = newSize;
	}



	int NodeIndex::insertNode(uint32_t, uint32_t, Buffer&);

	list_node* getListHead(uint32_t, list_node**);
	int destroyNodeIndex(NodeIndex*);

	int resizeIndex();


};


#endif