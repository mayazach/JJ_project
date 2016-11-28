#include <iostream>
#include "NodeIndex.h"
#include "HashNode.h"
#include "Buffer.h"
#include "ListNode.h"
#include "Ptr.h"

using namespace std;



int NodeIndex::insertNode(uint32_t nodeId, uint32_t nodeId2, Buffer& buffer)
{
	while (nodeId >= getSize())
	{
		resizeIndex();
	}

	if (nodeIndex[nodeId] == NULL)
	{
		nodeIndex[nodeId] = new Ptr(noOfNeighbors);
	}
	/*eisagwgh akmhs sto Index*/
	if (nodeIndex[nodeId]->insertNode(nodeId2) == -1)
	{
		cerr << "Edge " << nodeId << " " << nodeId2 << " already exists." << endl;
		return EXIT_SUCCESS;
	}

	/*eisagwgh akmhs sto buffer*/

	/*an den exei ginei allocate listnode sto buffer*/
	if (nodeIndex[nodeId]->storedInBuffer() == false)
	{
		uint32_t offset = 0;
		offset = buffer.insertNode(nodeId2);
		nodeIndex[nodeId]->setOffset(offset);
	}
	else
	{
		buffer.insertNode(nodeIndex[nodeId]->getOffset(), nodeId2);
	}

	return EXIT_SUCCESS;

}

int NodeIndex::resizeIndex()
{
	Ptr** tempNodeIndex;
	int newSize = 2 * size;
	tempNodeIndex = new Ptr*[newSize];

	memcpy(tempNodeIndex, nodeIndex, size*sizeof(Ptr*));
	delete[] nodeIndex;
	int i;
	for (i = size; i < newSize; i++)
	{
		tempNodeIndex[i] = NULL;// new Ptr(noOfNeighbors);
	}
	

	size =newSize;
	
	nodeIndex = tempNodeIndex;
	/*set Ptr*/
	return EXIT_SUCCESS;
}


list_node* NodeIndex::getListHead(uint32_t nodeId, list_node** buffer)
{
	uint32_t offset = nodeIndex[nodeId]->getOffset();

	return buffer[offset];
}

uint32_t* NodeIndex::getNodeNeighbors(uint32_t id, Buffer* buffer)
{
	uint32_t index;
	list_node *node;
	uint32_t *result;
	if ((id < size) && (nodeIndex[id]->storedInBuffer() == true))
	{
		index = nodeIndex[id]->getOffset();
		node = buffer->getListNode(index);
		result = node->getNeighbor();
		return result;
	}
	else
	{
		return NULL;
	}

}

int NodeIndex::getNoOfNeighbors(uint32_t id, Buffer* buffer)
{
	uint32_t index;
	list_node *node;
	uint32_t result=0;
	if ((size > id) && (nodeIndex[id]->storedInBuffer() == true))
	{
		index = nodeIndex[id]->getOffset();


		node = buffer->getListNode(index);
		result = node->getNoOfNeighbors();
	}
	else
	{
		return result = 0;
	}

	return result;

}

