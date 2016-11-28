#ifndef BUFFER_H
#define BUFFER_H
#include <iostream>
#include <cstring>
#include "ListNode.h"
#include "Ptr.h"
#include "Parse.h"
#include "Task.h"

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
		int i;
		
		for (i = 0; i < allocatedNodes; i++)
		{
			if (buffer[i] != NULL)
			{
				delete buffer[i];
			}
		}
		delete[] buffer;
	}

	list_node** getBuffer()
	{
		return buffer;
	}



	uint32_t  allocNewNode();
	list_node* getListNode(uint32_t);
	list_node* getLastNode(uint32_t);
	void setNext(list_node*&, int);
	/*eisagwgh kainourgiou kombou sto buffer */
	uint32_t insertNode(uint32_t);
	/*eisagwgh geitonwn gia kombous pou exoun ginei hdh allocate*/
	void insertNode(uint32_t, uint32_t);

};

#endif