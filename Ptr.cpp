#include "Ptr.h"
#include <iostream>

using namespace std;

/*sunarthseis gia thn dhmiourgia tou Hashtable*/

/*
int Ptr::hashfunction(const uint32_t n)
{
	return (n%size);
}*/
/*
int Ptr::insertNode(const uint32_t node, Buffer& buffer)
{


	int ret= hashtable->insert(node);
	if (ret == 2)
	{
		int nodesCount = offsetCount + 1,neighbors=0,i,j;
		uint32_t*  listNodeNeighbors;
		list_node* listNode;
		for (i = 0; i < nodesCount + 1; i++)
		{
			listNode = buffer.getListNode(offset[i]);
			listNodeNeighbors = listNode->getNeighbor();
			neighbors = listNode->getNoOfNeighbors();
			for (j = 0; j < neighbors; j++)
			{
				hashtable->rehash(listNodeNeighbors[j]);
			}
		}
		ret = hashtable->insert(node);
	}
	return ret;

}


*/



/*************************************/

