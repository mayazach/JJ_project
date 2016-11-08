#ifndef NODEINDEX_H
#define NODEINDEX_H
#include <iostream>
#include <cstring>
#include <string>
#include "Ptr.h"
#include "Buffer.h"
using namespace std;

class NodeIndex

{
	Ptr** nodeIndex;
	uint32_t size;
	uint32_t noOfNeighbors;
	void setSize(uint32_t newSize)
	{
		size = newSize;
	}

//	int destroyNodeIndex(NodeIndex*);
	int resizeIndex();


public:

	NodeIndex(const int _size, const int _noOfNeighbors)
	{
		/*desmeush mnhmhs gia ton pinaka*/
		nodeIndex = new Ptr*[_size];
		if (nodeIndex == NULL)
		{
			cerr << "NodeIndex: Memory allocation error." << endl;
		}
		size=_size;
		noOfNeighbors = _noOfNeighbors;

		int i;
		for (i = 0; i < size; i++)
		{
			nodeIndex[i] = new Ptr(noOfNeighbors);
		}
	}



	~NodeIndex()
	{

		int i;
		for (i = 0; i < size; i++)
		{
			delete nodeIndex[i];
		}

		delete[] nodeIndex;
	}

	uint32_t getSize()
	{
		return size;
	}	

	int insertNode(uint32_t, uint32_t, Buffer&);

	list_node* getListHead(uint32_t, list_node**);


	Ptr** getIndex()
	{
		return nodeIndex;
	}

	uint32_t* getNodeNeighbors(uint32_t id, Buffer* buffer);

	int getNoOfNeighbors(uint32_t id, Buffer* buffer);




};


#endif