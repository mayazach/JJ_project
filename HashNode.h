#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>
#include <stdint.h> 


/*Klash pou periexei to bucket kai deikth sto epomeno overflow bucket(an uparxei)*/
class hashNode
{
public:
	uint32_t* nodes;
	hashNode* next;
	int count;
	int maxBucketSize;
	
	hashNode() : nodes(NULL), next(NULL), count(0), maxBucketSize(0) {}
	hashNode(const int _maxBucketSize)
	{

		nodes = new uint32_t[_maxBucketSize];
		next = NULL;
		count = 0;
		maxBucketSize = _maxBucketSize;
	}


	void setHashNode(const int _maxBucketSize)
	{

		nodes = new uint32_t[_maxBucketSize];
		next = NULL;
		count = 0;
		maxBucketSize = _maxBucketSize;
	}
	

	uint32_t getCount()
	{
		return count;
	}

	uint32_t getMaxBucketSize()
	{
		return maxBucketSize;
	}

	hashNode* getNext()
	{
		return next;
	}

	void setNext(hashNode* _next)
	{
		next = _next;
	}

	bool edgeExists(uint32_t node)
	{
		uint32_t j;
		for (j = 0; j < count; j++)
		{
			if (nodes[j] == node)
			{
				return true;
			}
		}
		return false;
	}



	int insertNode(const uint32_t n)
	{
		nodes[count] = n;
		increaseCount();
		return EXIT_SUCCESS;
	}
	void increaseCount()
	{
		count++;
	}

	bool isFull()
	{
		if (count >= maxBucketSize)
		{
			return true;
		}
		return false;
	}




	/*void set_hashNode()
	{
		rec_array = NULL;
		next = NULL;
		count = 0;
	}
	int set_bucket(const int b)
	{
		rec_array = new MyRecord*[b];
		int i;
		for (i = 0; i < b; i++)
		{
			rec_array[i] = NULL;
		}
		return 0;

	}*/

	~hashNode()
	{
		if (nodes != NULL)
		{
			delete[] nodes;
		}
	}

};


/*~hashNode()
	{
		int i;
		if (nodes != NULL)
		{
			for (i = 0; i < count; i++)
			{
				if (rec_array[i] != NULL)
				{
					delete rec_array[i];
				}
			}
			delete[] rec_array;
		}
	}*/
#endif