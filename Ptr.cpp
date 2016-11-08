#include "Ptr.h"
#include <iostream>

using namespace std;

/*sunarthseis gia thn dhmiourgia tou Hashtable*/


int Ptr::hashfunction(const uint32_t n)
{
	return (n%size);
}

int Ptr::insertNode(const uint32_t node)
{

	int i = hashfunction(node);
	
	hashNode* lastBucket = getLastBucket(i,node);
	if (lastBucket != NULL)
	{
		hashNode* insertBucket = lastBucket;
		if (lastBucket->isFull() == true)
		{
			hashNode* newBucket = new hashNode(maxBucketSize);
			lastBucket->setNext(newBucket);
			insertBucket = newBucket;
		}

		insertBucket->insertNode(node);
		return EXIT_SUCCESS;
	}
	else
	{
		return -1;
	}
}

hashNode* Ptr::getLastBucket(const int index, const uint32_t node)
{
	hashNode* temp = &hashtable[index],*previous=temp;

	while (temp != NULL)
	{
		previous = temp;
		if (temp->edgeExists(node) == true)
		{
			return NULL;
		}

		temp = temp->getNext();
	}

	return previous;

}