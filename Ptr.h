#ifndef PTR_H
#define PTR_H
#include <iostream>
#include <stdint.h> 
#include <stdlib.h>
#include "HashNode.h"

using namespace std;

class Ptr
{
	hashNode * hashtable;
	int size;
	int maxBucketSize;
	int offset;
	int hashfunction(const uint32_t);




public:

	uint32_t getMaxBucketSize()
	{
		return maxBucketSize;
	}
	
	uint32_t getOffset()
	{
		return offset;
	}

	void setOffset(uint32_t _offset)
	{
		offset = _offset;
	}


	int insertNode(const uint32_t);

	hashNode* getLastBucket(const int,const uint32_t);


	Ptr()
	{
		maxBucketSize = 0;
		hashtable = NULL;
		size = 0;
		offset = -1;
	}

	/*void setPtr(uint32_t n)
	{

		maxBucketSize = 10;
		size = n;
		hashtable = new hashNode*[n];


		if (hashtable == NULL)
		{
			cerr << "Hashtable: Memory allocation error." << endl;
		}
		hashtableSize = n;
		offset = -1;
		int i;
		for (i = 0; i < hashtableSize; i++)
		{
			hashtable[i] = new hashNode(maxBucketSize);
		}

	}*/

	Ptr(uint32_t n)
	{
		maxBucketSize = 10;
		
		hashtable = new hashNode[n];
		
		if (hashtable == NULL)
		{
			cerr << "Hashtable: Memory allocation error." << endl;
		}
		int i;
		for (i = 0; i < n; i++)
		{
			hashtable[i].setHashNode(maxBucketSize);
		}

		size = n;
		offset = -1;
	}




	~Ptr()
	{
	//	bye();
		delete[] hashtable;
	}


};

#endif