#include <iostream>
#include "NodeIndex.h"
#include "HashNode.h"
#include "Buffer.h"
#include "ListNode.h"
#include "Ptr.h"
#include <math.h>

using namespace std;



int NodeIndex::insertNode(uint32_t nodeId, uint32_t nodeId2, Buffer& buffer)
{
	int ret;

	if (nodeId >= size)
	{
		double newNode = nodeId + 1;
		newNode = newNode / size;
		double times = ceil(newNode);
		resizeIndex(times);
	}


	/*an den exei eisax8ei o kombos sto index*/
	if (nodeIndex[nodeId] == NULL)
	{
		nodeIndex[nodeId] = new Ptr(noOfNeighbors);
		ret = addNewNode(nodeId);
		//	nodeIndex[nodeId].insertNode(nodeId2, buffer);
		int offset = buffer.insertNode(nodeId);
		nodeIndex[nodeId]->setHashtableOffset(ret);
		nodeIndex[nodeId]->addOffset(offset);
	}
	else
	{
		int hashIndex = nodeIndex[nodeId]->getHashtableOffset();
		ret = addNode(hashIndex, nodeId2, buffer);

		if (ret == -1)
		{
			return ret;
		}
		else if (ret == -2)
		{
			rehash(hashIndex, nodeId, nodeId2, buffer);
		}
		else
		{
			//	nodeIndex[nodeId].insertNode(nodeId2, buffer);
			int offset = nodeIndex[nodeId]->getOffset();
			int retOffset = buffer.insertNode(offset, nodeId);
			if (offset != retOffset)
			{
				nodeIndex[nodeId]->addOffset(offset);
			}
		}

	}


	/*eisagwgh akmhs sto buffer*/

	/*an den exei ginei allocate listnode sto buffer*/
	uint32_t offset = 0;
	if (nodeIndex[nodeId]->storedInBuffer() == false)
	{
		offset = buffer.insertNode(nodeId2);
		nodeIndex[nodeId]->setOffset(offset);
	}
	else
	{
		int storedOffset = nodeIndex[nodeId]->getOffset();
		offset = buffer.insertNode(storedOffset, nodeId2);
		if (storedOffset != offset)
		{
			nodeIndex[nodeId]->addOffset(offset);
		}
	}

	return EXIT_SUCCESS;

}

int NodeIndex::resizeIndex(const uint32_t times)
{
	int newSize = times * size;
	Ptr** tempNodeIndex = new Ptr*[newSize];
	
	//nodeIndex = new Ptr*[newSize];

	memcpy(tempNodeIndex, nodeIndex, size*sizeof(Ptr*));
	delete[] nodeIndex;
	nodeIndex = tempNodeIndex;
	int i;
	for (i = size; i < newSize; i++)
	{
		nodeIndex[i] = NULL;// new Ptr(noOfNeighbors);
	}

	size = newSize;

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
	if ((nodeIndex[id] != NULL) && (id < size) && (nodeIndex[id]->storedInBuffer() == true))
	{
		index = nodeIndex[id]->getOffsetArray()[0];
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
	uint32_t result = 0;
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




int NodeIndex::rehash(uint32_t hashIndex, uint32_t nodeId, uint32_t nodeId2,Buffer& buffer)
{
		int nodesCount = nodeIndex[nodeId]->getOffsetCount() + 1, neighbors = 0, i, j;
		uint32_t*  listNodeNeighbors, *offset = nodeIndex[nodeId]->getOffsetArray();
		list_node* listNode;
		for (i = 0; i < nodesCount; i++)
		{
			listNode = buffer.getListNode(offset[i]);
			listNodeNeighbors = listNode->getNeighbor();
			neighbors = listNode->getNoOfNeighbors();
			for (j = 0; j < neighbors; j++)
			{
				hashtableIndex[hashIndex]->rehash(listNodeNeighbors[j]);
			}
		}
	int	ret = hashtableIndex[hashIndex]->insert(nodeId2);
	return ret;
	
}