#include <iostream>
#include "NodeIndex.h"
#include "HashNode.h"
#include "Buffer.h"
#include "ListNode.h"
#include "Ptr.h"

using namespace std;



int NodeIndex::insertNode(uint32_t nodeId, uint32_t nodeId2, Buffer& buffer)
{
	if (nodeId >= getSize())
	{
		resizeIndex();
	}

	/*eisagwgh akmhs sto Index*/
	if (nodeIndex[nodeId]->insertNode(nodeId2) == -1)
	{
		cerr << "Edge " << nodeId << " " << nodeId2 << " already exists." << endl;
		return EXIT_SUCCESS;
	}

	/*eisagwgh akmhs sto buffer*/

	/*an den exei ginei allocate listnode sto buffer*/
	if (nodeIndex[nodeId]->getOffset() == -1)
	{
		int offset = -1;
		offset = buffer.insertNode(offset, nodeId2);
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
	tempNodeIndex = new Ptr*[size * 2];

	int i;
	for (i = size; i < size * 2; i++)
	{
		tempNodeIndex[i] = new Ptr(noOfNeighbors);
	}
	memcpy(tempNodeIndex, nodeIndex, size*sizeof(Ptr*));
	size *= 2;
	delete[] nodeIndex;
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
	index = nodeIndex[id]->getOffset();
	node = buffer->getListNode(index);
	result = node->getNeighbor();
	return result;
}

int NodeIndex::getNoOfNeighbors(uint32_t id, Buffer* buffer)
{
	uint32_t index;
	list_node *node;
	uint32_t result;
	index = nodeIndex[id]->getOffset();
	node = buffer->getListNode(index);
	result = node->getNoOfNeighbors();
	return result;

}

