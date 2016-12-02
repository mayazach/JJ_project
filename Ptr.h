#ifndef PTR_H
#define PTR_H
#include <iostream>
#include <stdint.h> 
#include <stdlib.h>
#include "Hashtable.h"
#include "HashNode.h"
#include "Buffer.h"
using namespace std;

class Ptr
{

	uint32_t size;
	uint32_t hashtableOffset;
	int maxBucketSize;
	uint32_t* offset;
	bool inBuffer;
	int offsetCount;
	int offsetSize;





public:


	uint32_t getMaxBucketSize()
	{
		return maxBucketSize;
	}

	uint32_t* getOffsetArray()
	{
		return offset;
	}


	uint32_t getOffset()
	{
		return offset[offsetCount];
	}

	void setOffset(uint32_t _offset)
	{
		addOffset(_offset);
		inBuffer = true;
	}

	int getOffsetCount()
	{
		return offsetCount;
	}

	int getOffsetSize()
	{
		return offsetSize;
	}

	int getHashtableOffset()
	{
		return hashtableOffset;
	}

	void setHashtableOffset(int h)
	{
		hashtableOffset=h;
	}


	//int insertNode(const uint32_t, Buffer&);


	Ptr()
	{
		maxBucketSize = 0;
		offsetCount = -1;
		hashtableOffset = 0;
		size = 0;
		offsetSize = 0;
		inBuffer = false;		size = 0;
		offset = 0;
		inBuffer = false;
	}

	Ptr(const Ptr&p)
	{

		offset = p.offset;
		offsetCount = p.offsetCount;
		hashtableOffset = p.hashtableOffset;
		size = p.size;
		offsetSize = p.offsetSize;
		inBuffer = p.inBuffer;
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

		/*hashtable = new Hashtable<uint32_t>(n);

		if (hashtable == NULL)
		{
			cerr << "Hashtable: Memory allocation error." << endl;
		}
		*/
		offset = new uint32_t[n];
		if (offset == NULL)
		{
			cerr << "Offset array: Memory allocation error." << endl;
		}

		offsetCount = -1;
		hashtableOffset = 0;
		size = n;
		offsetSize = n;
		inBuffer = false;
	}


	void setPtr(uint32_t n)
	{
		maxBucketSize = 10;

		/*hashtable = new Hashtable<uint32_t>(n);

		if (hashtable == NULL)
		{
		cerr << "Hashtable: Memory allocation error." << endl;
		}
		*/
		offset = new uint32_t[n];
		if (offset == NULL)
		{
			cerr << "Offset array: Memory allocation error." << endl;
		}

		offsetCount = -1;
		hashtableOffset = 0;
		size = n;
		offsetSize = n;
		inBuffer = false;
	}


/*	bool edgeExists(uint32_t node2)
	{

		if (hashtable->keyExists(node2) == true)
		{
			return true;
		}
		return false;
	} */

	bool storedInBuffer()
	{
		return inBuffer;
	}

	void addOffset(uint32_t _offset)
	{
		offsetCount++;
		if (offsetCount >= offsetSize)
		{
			int newSize = offsetSize * 2;

			uint32_t* tempOffset = new uint32_t[newSize];
			memcpy(tempOffset, offset, offsetSize*sizeof(uint32_t));
			delete[] offset;
			offset = tempOffset;
			offsetSize = newSize;
		}

		offset[offsetCount] = _offset;
	}


	void clean()
	{
	//	hashtable->clean();
		delete[] offset;
		offset=NULL;
	}


	~Ptr()
	{
		//	bye();
		//hashtable->clean();
		//delete hashtable;
		if(offset!=NULL)
		{
		delete[] offset;
		}
	}


};

#endif