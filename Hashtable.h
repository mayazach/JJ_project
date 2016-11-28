#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include "HashNode.h"
#include <math.h>
#include <string.h>
using namespace std;

template <typename K>
class Hashtable {


private:

	hashNode<K>** hashtable;

	//int maxBucketSize;

	/********************/
	float loadfactor;
	int size;/*mege8os tou pinaka*/
	int bucketSize;/*mege8os tou bucket*/
	int initialSize;
	int m;
	int p;
	int round;
	int count;
	int capacity;

	bool checkLoadfactor()
	{
		if (count > capacity*loadfactor)/*xreiazetai na ginei split*/
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	/*
	int hashfunction(const K k)
	{
		K denom = pow(2, round)*m;
		return (k % (denom));
	}
	int hashfunction(const K k, const int new_round)
	{
		K denom = pow(2, new_round)*m;
		int mod = k % (denom);
		if (mod >= size)
		{
			return (hashfunction(k));
		}
		else
		{
			return mod;
		}
	}

	*/

	long hashfunction(const K k)
	{
		return (k % size);
	}


	/***************************************************************/
public:
	void resize();
	int insert(K);
	int split();
	int reinsertInBucket(hashNode<K>*, K);
	int rehash(const int, K);
	hashNode<K>* getLastBucket(const int, const uint32_t);

	

	bool keyExists(K key)
	{
		int i = hashfunction(key);

	//	if (i <= p)/*Xrhsh ths epomenhs hash function*/
		//{
			//i = hashfunction(key, round + 1);
		//}

		return hashtable[i]->keyExists(key);

	}


	/***************************************************************/



public:

	void set_capacity()
	{
		capacity = size*bucketSize;
	}

	int set_bucketSize(const int i)
	{
		if (i <= 0)
		{
			return -1;
		}
		else
		{
			bucketSize = i;
			return 0;
		}
	}

	int getBucketSize()
	{
		return bucketSize;
	}

	void setLoadfactor(const float i)
	{
		loadfactor = i;
	}

	float getLoadfactor()
	{
		return loadfactor;
	}

	int getCount()
	{
		return count;
	}

	void setSize(const int i)
	{
		size = i;
	}

	int getSize()
	{
		return size;
	}

	void setInitialSize()
	{
		initialSize = size;
	}
	void setM()
	{
		m = size;
	}

	/*
	uint32_t getMaxBucketSize()
	{
		return maxBucketSize;
	}*/


	Hashtable(const int n)
	{
		// construct zero initialized hash table of size
		bucketSize = n;
		size = n;
		capacity = size*bucketSize;
		initialSize = n;
		m = size;
		p=0;
		round=0;
		count=0;
		loadfactor = 0.75;

		hashtable = new hashNode<K>*[n];
			if (hashtable == NULL)
		{
			cerr << "Hashtable: Memory allocation error." << endl;
		}

		uint32_t i;
		for (i = 0; i < n; i++)
		{
		//	hashtable[i] = new hashNode<K>(bucketSize);
			hashtable[i] = NULL;
		}

		size = n;

	}

	void clean()
	{
		int i;
		hashNode<K>* temp;
		hashNode<K>* temp2;
		for (i = 0; i < size; i++)
		{
			if (hashtable[i] != NULL)
			{
				temp = hashtable[i];
				while (temp != NULL)
				{
					temp2 = temp;
					temp = temp->getNext();
					delete temp2;
					temp2 = NULL;
				}
			}
		}
		delete[] hashtable;

	}

	~Hashtable()
	{
		// destroy all buckets one by one
		/*	for (int i = 0; i < size; ++i)
			{
			hashNode<K> *entry = table[i];
			while (entry != NULL)
			{
			hashNode<K> *prev = entry;
			entry = entry->getNext();
			delete prev;
			}
			table[i] = NULL;
			}
			// destroy the hash table
			delete[] table;*/
	}

	/*bool get(const K &key, V &value)
	{
	unsigned long hashValue = hashFunc(key);
	hashNode<K> *entry = table[hashValue];

	while (entry != NULL)
	{
	if (entry->getKey() == key)
	{
	value = entry->getValue();
	return true;
	}
	entry = entry->getNext();
	}
	return false;
	}

	void put(const K &key, const V &value)
	{
	unsigned long hashValue = hashFunc(key);
	hashNode<K> *prev = NULL;
	hashNode<K> *entry = table[hashValue];

	while (entry != NULL && entry->getKey() != key)
	{
	prev = entry;
	entry = entry->getNext();
	}

	if (entry == NULL)
	{
	entry = new hashNode<K>(key, value);
	if (prev == NULL)
	{
	// insert as first bucket
	table[hashValue] = entry;
	}
	else
	{
	prev->setNext(entry);
	}
	}
	else
	{
	// just update the value
	entry->setValue(value);
	}
	}

	void remove(const K &key)
	{
	unsigned long hashValue = hashFunc(key);
	hashNode<K> *prev = NULL;
	hashNode<K> *entry = table[hashValue];

	while (entry != NULL && entry->getKey() != key)
	{
	prev = entry;
	entry = entry->getNext();
	}

	if (entry == NULL)
	{
	// key not found
	return;
	}
	else
	{
	if (prev == NULL)
	{
	// remove first bucket of the list
	table[hashValue] = entry->getNext();
	}
	else
	{
	prev->setNext(entry->getNext());
	}
	delete entry;
	}
	}

	private:
	// hash table
	hashNode<K> **table;
	F hashFunc;

	*/








};



#endif