#include <iostream>
#include <algorithm>
#include "Buffer.h"
#include "Ptr.h"

using namespace std;


int Buffer::resizeBuffer()
{

	int newSize = bufferSize * 2;
	list_node** tempBuffer = buffer;
	buffer = new list_node*[newSize];
	if (buffer == NULL)
	{
		cerr << "Resise Buffer: Memory allocation error." << endl;
		return EXIT_FAILURE;
	}

	memcpy(buffer, tempBuffer, bufferSize*sizeof(list_node*));

	delete[] tempBuffer;
	bufferSize *= 2;


	return EXIT_SUCCESS;
}




uint32_t Buffer::allocNewNode()
{
	/*an o buffer den exei alles dia8esimes 8eseis, diplasiazetai*/
	if (allocatedNodes >= bufferSize)
	{
		if (resizeBuffer() == EXIT_FAILURE)
		{
			return EXIT_FAILURE;
		}
	}

	buffer[allocatedNodes] = new list_node(noOfNeighbors);

	if (buffer[allocatedNodes] == NULL)
	{
		cerr << "Hashtable: Memory allocation error." << endl;
	}
	uint32_t offset = allocatedNodes;
	allocatedNodes++;

	return offset;
}


list_node* Buffer::getListNode(uint32_t offset)
{
	return buffer[offset];
}

/*

list_node* Buffer::getLastNode(uint32_t offset)
{
	list_node* listNodePtr = buffer[offset], *node = listNodePtr;
	uint32_t nextNodeOffset = offset;
	while (listNodePtr != NULL)
	{
		node = listNodePtr;
		nextNodeOffset = node->getNextListNode();
		if (nextNodeOffset != 0)
		{
			listNodePtr = buffer[nextNodeOffset];
		}
		else
		{
			listNodePtr = NULL;
		}
	}

	return node;

}


*/

void Buffer::setNext(list_node*& node, int nextOffset)
{
	node->setNext(nextOffset);
}


uint32_t Buffer::insertNode(uint32_t nodeId2)
{
	/*an o kombos den exei ginei allocate*/

	uint32_t offset = allocNewNode();
	buffer[offset]->addNeighbor(nodeId2);
	return offset;

}


uint32_t Buffer::insertNode(uint32_t offset, uint32_t nodeId2)
{
	/*an o kombos den exei ginei allocate*/

	list_node* node = buffer[offset];

	if (node->isFull() == true)
	{
		uint32_t newOffset = allocNewNode();
		setNext(node, newOffset);
		node = buffer[newOffset];
		offset = newOffset;
	}
	node->addNeighbor(nodeId2);
	return offset;

}

