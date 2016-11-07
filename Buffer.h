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

	Buffer(const int _bufferSize, int n)
	{
		buffer = new list_node*[bufferSize];

		if (buffer == NULL)
		{
			cerr << "Buffer: Memory allocation error." << endl;
		}
		memset(buffer, NULL, sizeof(list_node*) * bufferSize);
		bufferSize = _bufferSize;
		allocatedNodes = 0;
		noOfNeighbors = n;
	}

	~Buffer()
	{
		int i;
		for (i = 0; i < bufferSize; i++)
		{
			if (buffer[i] != NULL)
			{
				delete buffer[i];
			}
		}
		delete buffer;
	}

	list_node** getBuffer()
	{
		return buffer;
	}


	uint32_t  allocNewNode();
	list_node* getListNode(uint32_t);
	void setNext(list_node*, uint32_t);
	int insertNode(uint32_t, uint32_t);

};


#endif
