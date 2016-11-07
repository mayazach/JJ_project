#ifndef HASHNODE_H
#define HASHNODE_H
#include <iostream>
#include <string>
#include <stdint.h> 


using namespace std;


class hashNode
{
private:
	uint32_t* nodes;
	hashNode* next;
	uint32_t maxBucketSize;
	uint32_t bucketSize;

public:

	hashNode(uint32_t n)
	{
		nodes = new uint32_t[n];
		maxBucketSize = n;
		next = NULL;
		bucketSize = 0;
	}

	~hashNode()
	{
		uint32_t* node_ptr;
		if (nodes != NULL)
		{
			/*node_ptr = nodes;
			nodes = NULL;
			delete node_ptr;*/
			delete[] nodes;
		}
	}


	uint32_t getBucketSize()
	{
		return bucketSize;
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
		for (j = 0; j < bucketSize; j++)
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
		nodes[bucketSize] = n;
		increaseBucketSize();
		return EXIT_SUCCESS;
	}
	void increaseBucketSize()
	{
		bucketSize++;
	}

	bool isFull()
	{
		if (bucketSize >= maxBucketSize)
		{
			return true;
		}
		return false;
	}

};

/*klash me to hashtable kai sunarthseis me oles tis leitourgies pou efarmozontai se auton*/
class HashTable
{
private:
	int size;
	uint32_t maxBucketSize;
	int hashfunction(const uint32_t);

	int bye();

public:

	uint32_t getMaxBucketSize()
	{
		return maxBucketSize;
	}
	hashNode** hashtable;
	int create();


	void set_size(const int);

	int insertNode(const uint32_t);

	HashTable(const uint32_t _size, const uint32_t _maxBucketSize)
	{
		hashtable = new hashNode*[_size];
		if (hashtable == NULL)
		{
			cerr << "Hashtable: Memory allocation error." << endl;
		}


		memset(hashtable, NULL, sizeof(hashNode*) * _size);
		size = _size;
		maxBucketSize = _maxBucketSize;
	}
	~HashTable()
	{
		bye();
		delete[] hashtable;
	}
};



#endif

