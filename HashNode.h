#ifndef HASHNODE_H
#define HASHNODE_H

#include <iostream>
#include <stdint.h> 
#include <stdlib.h> 

/*Klash pou periexei to bucket kai deikth sto epomeno overflow bucket(an uparxei)*/
template <typename K> class hashNode {


private:

	K* keys;
	//hashNode<K>* next;
	int count;
	int maxBucketSize;

public:

	//hashNode() : keys(NULL), next(NULL), count(0), maxBucketSize(0) {}
	hashNode(const int _maxBucketSize)
	{

		keys = new K[_maxBucketSize];
//		next = NULL;
		count = 0;
		maxBucketSize = _maxBucketSize;
	}


	void sethashNode(const int _maxBucketSize)
	{

		keys = new K[_maxBucketSize];
	//	next = NULL;
		count = 0;
		maxBucketSize = _maxBucketSize;
	}

	K* getKeys()
	{
		return keys;
	}

	int getCount()
	{
		return count;
	}

	/*
	int getMaxBucketSize()
	{
		return maxBucketSize;
	}*/

/*	hashNode<K>* getNext()
	{
		return next;
	}*/

/*	void setNext(hashNode* _next)
	{
		next = _next;
	}
	*/
	bool keyExists(K key)
	{
		int j;
		for (j = 0; j < count; j++)
		{
			if (keys[j] == key)
			{
				return true;
			}
		}
		return false;
	}



	int insertKey(K n)
	{
		keys[count] = n;
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




	/*void sethashNode()
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
		if (keys != NULL)
		{
			delete[] keys;
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