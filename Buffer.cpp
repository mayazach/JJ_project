#include <iostream>
#include "Buffer.h"
#include "Ptr.h"

using namespace std;


int Buffer::resizeBuffer()
{
	list_node** tempBuffer = buffer;

	buffer = new list_node*[bufferSize * 2];
	if (buffer == NULL)
	{
		cerr << "Buffer: Memory allocation error." << endl;
	}
	
	/*arxikopoihsh twn 8esewn tou pinaka me NULL*/
	memset(buffer, NULL, sizeof(list_node*) * bufferSize*2);

	memcpy(buffer, tempBuffer, bufferSize*sizeof(list_node*));

	
	/*diplasiasmos mege8ous tou buffer*/
	bufferSize *= 2;
	//delete[] tempBuffer;
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
	list_node* listNodePtr = buffer[offset], *node = listNodePtr;
	while (listNodePtr != NULL)
	{
		node = listNodePtr;
		listNodePtr = listNodePtr->getNextListNode();
	}

	return node;

}




void Buffer::setNext(list_node* node, uint32_t nextOffset)
{
	node->setNext(buffer[nextOffset]);
}


int Buffer::insertNode(uint32_t offset, uint32_t nodeId2)
{
	/*an o kombos den exei ginei allocate*/

	if (offset == -1)
	{
		offset = allocNewNode();
		buffer[offset]->addNeighbor(nodeId2);

	}
	else
	{
		list_node* node = getListNode(offset);
		if (node->isFull() == true)
		{
			uint32_t offset = allocNewNode();
			setNext(node, offset);
		}
		node->addNeighbor(nodeId2);
	}


	return offset;
}