#ifndef PTR_H
#define PTR_H
#include <iostream>
#include <stdint.h> 
#include <stdlib.h>
#include "Hashtable.h"
#include "HashNode.h"

using namespace std;

class Ptr
{
	Hashtable<uint32_t> * hashtable;
	int size;
	int maxBucketSize;
	uint32_t offset;
	bool inBuffer;
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
		inBuffer = true;
	}


	int insertNode(const uint32_t);


	Ptr()
	{
		maxBucketSize = 0;
		hashtable = NULL;
		size = 0;
		offset = 0;
		inBuffer = false;
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
	//	maxBucketSize = 10;

	/*	hashtable = new Hashtable<uint32_t>(n);

		if (hashtable == NULL)
		{
			cerr << "Hashtable: Memory allocation error." << endl;
		}*/
		hashtable = NULL;


		size = n;
		offset = 0;
		inBuffer = false;
	}

	bool edgeExists(uint32_t node2)
	{
		if (hashtable->keyExists(node2) == true)
		{
			return true;
		}
		return false;
	}

	bool storedInBuffer()
	{
		return inBuffer;
	}



	void clean()
	{
		hashtable->clean();

	}


	~Ptr()
	{
		//	bye();
		hashtable->clean();
		delete hashtable;
	}


};

#endif