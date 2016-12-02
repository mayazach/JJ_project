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
	Hashtable<uint32_t>** hashtableIndex;
	uint32_t hashtableCount;
	uint32_t hashtableSize;
	int hashfunction(const uint32_t);
	uint32_t size;
	uint32_t noOfNeighbors;
	void setSize(uint32_t newSize)
	{
		size = newSize;
	}

	//	int destroyNodeIndex(NodeIndex*);
	int resizeIndex(uint32_t);


public:

	NodeIndex(const uint32_t _size, const int _noOfNeighbors)
	{
		/*desmeush mnhmhs gia ton pinaka*/
		nodeIndex = new Ptr*[_size];
		if (nodeIndex == NULL)
		{
			cerr << "NodeIndex: Memory allocation error." << endl;
		}

		size = _size;

		uint32_t i;
		for (i = 0; i < size; i++)
		{
			//nodeIndex[i] = new Ptr(noOfNeighbors);
			nodeIndex[i] = NULL;
		}

		hashtableIndex = new Hashtable<uint32_t>*[_size];



		noOfNeighbors = _noOfNeighbors;
		hashtableCount = 0;
		hashtableSize = _size;

	}

	int addNewNode(uint32_t node)
	{
		if (hashtableCount >= hashtableSize)
		{
			resizeHashtableIndex();
		}
		int ret;
		hashtableIndex[hashtableCount] = new Hashtable<uint32_t>(noOfNeighbors);
		ret = hashtableIndex[hashtableCount]->insert(node);
		hashtableCount++;
		return hashtableCount - 1;
	}

	int addNode(uint32_t hashIndex, uint32_t nodeId, Buffer& buffer)
	{
		int ret;
		ret = hashtableIndex[hashIndex]->insert(nodeId);

		/*an to hashtable tou kombou exei gemisei*/
		
		return ret;
	}


	void resizeHashtableIndex()
	{
		Hashtable<uint32_t> ** temp = hashtableIndex;
		uint32_t newSize = hashtableSize * 2;
		hashtableIndex = new Hashtable<uint32_t>*[newSize];
		memcpy(hashtableIndex, temp, hashtableSize*sizeof(Hashtable<uint32_t>*));
		delete[] temp;
		hashtableSize = newSize;
	}

	int rehash(uint32_t, uint32_t, uint32_t, Buffer&);



	void clean()
	{
		uint32_t i,j;
		for (i = 0; i < size; i++)
		{
			if (nodeIndex[i] != NULL)
			{
				j = nodeIndex[i]->getHashtableOffset();
				nodeIndex[i]->clean();
				delete nodeIndex[i];
				hashtableIndex[j]->clean();
				delete hashtableIndex[j];
			}
		}	delete[] hashtableIndex;
		delete[] nodeIndex;
	}
	~NodeIndex()
	{

		uint32_t i;
		/*	for (i = 0; i < size; i++)
			{
			if (nodeIndex[i]  NULL)
			{
			delete nodeIndex[i];
			}
			}*/



	//	delete[] nodeIndex;
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