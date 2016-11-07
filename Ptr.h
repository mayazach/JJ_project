#ifndef PTR_H
#define PTR_H
#include <iostream>
#include <stdint.h> 
#include "ListNode.h"
#include "HashNode.h"
#include "Hashtable.cpp"

class Ptr

{
	uint32_t offset;
	HashTable*  hashtable;
	uint32_t hashtableSize;


	public:




	Ptr(uint32_t n)
	{
		uint32_t maxBucketSize = 10;
		hashtable = new HashTable(n,maxBucketSize);

		if (hashtable == NULL)
		{
			cerr << "Hashtable: Memory allocation error." << endl;
		}
		hashtableSize = n;
		offset = -1;
	}

	bool insert_node(uint32_t nodeId)
	{
		/*an uparxei hdh h akmh*/
		if (hashtable->insertNode(nodeId) == -1)
		{
			return false;
		}
		
		return true;
	}
	

	uint32_t getOffset()
	{
		return offset;
	}

	void setOffset(uint32_t _offset)
	{
		offset=_offset;
	}


};


#endif
