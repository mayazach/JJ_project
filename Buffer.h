#ifndef BUFFER_H
#define BUFFER_H
#include <iostream>
#include <cstring>
#include "ListNode.h"

using namespace std;


class Buffer {

	list_node** buffer;
	int bufferSize;
	int allocatedNodes;
	int noOfNeighbors;
	int resizeBuffer();

public:

	Buffer(const int _bufferSize, const int _noOfneighbors)
	{
		buffer = new list_node*[_bufferSize];
		bufferSize = _bufferSize;
		allocatedNodes = 0;
		noOfNeighbors = _noOfneighbors;

	}

	~Buffer()
	{
		//	deleteBufferArray();
	}

	list_node** getBuffer()
	{
		return buffer;
	}



	uint32_t  allocNewNode();
	list_node* getListNode(uint32_t);
	void setNext(list_node*, int);
	int insertNode(uint32_t, uint32_t);

};

#endif