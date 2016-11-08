#include <iostream>
#include "NodeIndex.h"
#include "HashNode.h"
#include "Buffer.h"
#include "ListNode.h"
#include "Ptr.h"
using namespace std;

int NodeIndex::insertNode(uint32_t nodeId, uint32_t nodeId2, Buffer& buffer)
{
	bool newNode = false;

	while (nodeId >= getSize())//diplasiasmos tou pinaka
	{
		resizeIndex();
	}

	if(nodeId > size){
		return -1;
	}

	if (nodeIndex[nodeId] == NULL)
	{
		nodeIndex[nodeId] = new Ptr(noOfNeighbors);
		if (nodeIndex[nodeId] == NULL)
		{
			cerr << "Ptr: Memory allocation error." << endl;
			return EXIT_FAILURE;
		}
		newNode = true;
	}


	if (nodeIndex[nodeId]->insert_node(nodeId2) == false)
	{
		cerr << "Edge " << nodeId << " " << nodeId2 << " already exists." << endl;
		return EXIT_SUCCESS;
	}
	else
	{
		if (newNode == true)/*dhmiourgeitai kainourgios kombos sto Buffer*/
		{
			uint32_t offset = -1;
			offset = buffer.insertNode(offset, nodeId2);
			nodeIndex[nodeId]->setOffset(offset);
		}
		else /*an uparxei hdh o kombos sto Buffer*/
		{
			buffer.insertNode(nodeIndex[nodeId]->getOffset(), nodeId2);
			list_node* node = buffer.getListNode(nodeIndex[nodeId]->getOffset());

		}


	}

	return EXIT_SUCCESS;
}


int NodeIndex::resizeIndex()
{
	Ptr** tempNodeIndex;

	uint32_t _size = getSize();

	tempNodeIndex = nodeIndex;
	nodeIndex = new Ptr*[_size * 2];

	if (nodeIndex == NULL)
	{
		cerr << "NodeIndex: Memory allocation error." << endl;
		return EXIT_FAILURE;
	}

	/*arxikopoihsh twn upoloipwn 8esewn tou pinaka me NULL*/
	memset(nodeIndex, NULL, sizeof(Ptr*) * _size * 2);

	memcpy(nodeIndex, tempNodeIndex, _size*sizeof(Ptr*));

	/*diplasiasmos mege8ous tou index*/
	setSize(_size * 2);
	delete[] tempNodeIndex;

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
	if(nodeIndex[id] != NULL){
		index = nodeIndex[id]->getOffset();
		node = buffer->getListNode(index);
		result =  node->getNeighbor();
		return result;}
	else return NULL;
}

int NodeIndex::getNoOfNeighbors(uint32_t id, Buffer* buffer)
{
        uint32_t index;
        list_node *node;
        uint32_t result;
	if(nodeIndex[id] != NULL){
	        index = nodeIndex[id]->getOffset();
	        node = buffer->getListNode(index);
	        result =  node->getNoOfNeighbors();
	        return result;}
	else return 0;
}
