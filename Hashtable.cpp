#include "HashNode.h"
#include <iostream>

using namespace std;

/*sunarthseis gia thn dhmiourgia tou Hashtable*/

void HashTable::set_size(const int s)
{
	size = s;
}

int HashTable::hashfunction(const uint32_t n)
{
	return (n%size);
}




int HashTable::insertNode(const uint32_t node)
{
	int i, bucketSize, maxBucketSize;

	maxBucketSize = getMaxBucketSize();


	i = hashfunction(node);

	hashNode* temp = hashtable[i];
	hashNode* previous = hashtable[i];
	while (temp != NULL)
	{
		bucketSize = temp->getBucketSize();

		if (temp->edgeExists(node) == true)
		{
			return -1;
		}
		previous = temp;
		temp = temp->getNext();
	}

	/*eisagwgh se uparxon bucket*/
	if (previous != NULL&&previous->isFull() == false)
	{
		previous->insertNode(node);
		return true;
	}
	else /*dhmiourgia neou bucket*/
	{
		maxBucketSize = getMaxBucketSize();
		hashNode* newHashNode = new hashNode(maxBucketSize);

		newHashNode->insertNode(node);
		if (hashtable[i] == NULL)
		{
			hashtable[i] = newHashNode;
		}
		else
		{
			previous->setNext(newHashNode);
		}

		return EXIT_SUCCESS;
	}
}




int HashTable::bye()
{
	int i;

	hashNode *next;
	for (i = 0; i < size; i++)
	{
		hashNode* hashnode = hashtable[i];
		if (hashnode != NULL)
		{
			next = hashnode->getNext();
			while (hashnode != NULL)
			{
				delete hashnode;
				hashnode = next;

				if (hashnode != NULL)
				{
					next = hashnode->getNext();
				}
			}
		}

		hashtable[i] = NULL;
	}

	return EXIT_SUCCESS;
}