#include <iostream>
#include "Hashtable.h"
#include <stdint.h>

using namespace std;

template <typename K>
int Hashtable<K>::insert(K key)
{
	/*Eisagwgh sto hash table*/
	int i;
	hashNode<K>* insertBucket;

	i = hashfunction(key);

	//	if (i <= p)/*Xrhsh ths epomenhs hash function*/
	//	{
	//		i = hashfunction(key, round + 1);
	//	}

	if (hashtable[i] != 0)
	{

		hashNode<K> * lastBucket = getLastBucket(i, key);
		if (lastBucket != NULL)
		{
			insertBucket = lastBucket;
			if (lastBucket->isFull() == true)
			{
				hashNode<K>* newBucket = new hashNode<K>(bucketSize);
				lastBucket->setNext(newBucket);
				insertBucket = newBucket;
			}

			insertBucket->insertKey(key);

			count++;

			if (checkLoadfactor() == true)
			{
				/*split to bucket sto opoio deixnei to p kai aukshsh tou deikth p*/
				resize();
			}



			return EXIT_SUCCESS;
		}
		else /* to stoixeio uparxei hdh*/
		{
			return -1;
		}
	}
	else
	{
		hashtable[i] = new hashNode<K>(bucketSize);
		hashtable[i]->insertKey(key);

		count++;

		if (checkLoadfactor() == true)
		{
			/*split to bucket sto opoio deixnei to p kai aukshsh tou deikth p*/
			resize();
		}
		return EXIT_SUCCESS;
	}

}


/*aukshsh mege8ous tou pinaka*/
template <typename K>
void Hashtable<K>::resize()
{
	
	hashNode<K> ** tempHashtable = hashtable;
	hashNode<K> * temp, *previous;
	int oldSize = size, count = 0, index, i, j, oldCount = getCount();
	K* keys;
	size *= 2;

	hashtable = new hashNode<K>*[size];
	for (j = 0; j < size; j++)
	{
		hashtable[j] = NULL;
	}

	for (i = 0; i < oldSize; i++)
	{
		if (oldCount <= 0)
		{
			break;
		}
		temp = tempHashtable[i];
		while (temp != NULL)
		{
			count = temp->getCount();
			keys = temp->getKeys();
			for (j = 0; j < count; j++)
			{
				index = hashfunction(keys[j]);
				rehash(index, keys[j]);
				oldCount--;
			}
			previous = temp;
			temp = temp->getNext();
			delete previous;
		}


	}


	delete[] tempHashtable;
}



/*epistrefei to teleutaio bucket mias sugkekrimenhs 8eshs tou hashtable*/
template <typename K>
hashNode<K>* Hashtable<K>::getLastBucket(const int index, const uint32_t node)
{
	hashNode<K>* temp = hashtable[index], *previous = temp;

	while (temp != NULL)
	{
		previous = temp;
		if (temp->keyExists(node) == true)
		{
			return NULL;
		}

		temp = temp->getNext();
	}

	return previous;

}


/*eisagwgh sto hashtable*/



/*resize tou hashtable kai anakatanomh twn stoixeiwn tou bucket */

template <typename K>
int Hashtable<K>::split()
{
	/*Split tou hash table*/
	resize();
	int n;
	hashNode<K>* temp = (hashtable[p]), *next = NULL;
	hashNode<K>* temp_prev = temp;

	int mod = 0, k;
	hashNode<K>* newHashNode = new hashNode<K>(getBucketSize());

	temp = hashtable[p];
	K* keys;
	while (temp != NULL)
	{
		k = temp->getCount();
		for (n = 0; n < k; n++)/*Gia ola ta stoixeia tou bucket*/
		{
			keys = temp->getKeys();
			//		mod = hashfunction(keys[n], round + 1);

			if ((mod != p) && (mod >= 0))
			{
				/*eisagwgh se diaforetiko bucket tou pinaka*/
				rehash(mod, keys[n]);
				//	temp->count--;
			}
			else
			{
				reinsertInBucket(newHashNode, keys[n]);
			}

		}
		temp = temp->getNext();

	}

	next = NULL;
	temp = hashtable[p];

	while (temp != NULL)
	{
		next = temp->getNext();
		delete temp;
		temp = next;
	}

	hashtable[p] = newHashNode;


	p++;
	/*An exei diplasiastei to mege8os tou hash table*/
	if (size == 2 * initialSize)
	{
		round++;
		initialSize = initialSize * 2;
		p = 0;
	}

	return 0;

}



/*rehash stoixeiou kai eisagwgh se diaforetikh 8esh tou hashtable*/
template <typename K>
int Hashtable<K>::reinsertInBucket(hashNode<K>* hashnode, K key)
{
	/*Eisagwgh sto hash table*/

	hashNode<K> *temp = hashnode, *previous = temp, *insertBucket;

	while (temp != NULL)
	{
		previous = temp;
		temp = temp->getNext();
	}

	temp = previous;

	if (temp->isFull() == true)
	{
		hashNode<K>* newBucket = new hashNode<K>(bucketSize);
		temp->setNext(newBucket);
		insertBucket = newBucket;
	}
	else
	{
		insertBucket = temp;
	}

	insertBucket->insertKey(key);

	return EXIT_SUCCESS;

}




template <typename K>
int Hashtable<K>::rehash(const int index, K key)
{
	/*Eisagwgh sto hash table*/

	hashNode<K>* temp = hashtable[index], *previous = temp, *insertBucket;

	if (hashtable[index] != NULL)
	{
		while (temp != NULL)
		{
			previous = temp;
			temp = temp->getNext();
		}

		temp = previous;


		if (temp->isFull() == true)
		{
			hashNode<K>* newBucket = new hashNode<K>(bucketSize);
			temp->setNext(newBucket);
			insertBucket = newBucket;
		}
		else
		{
			insertBucket = temp;
		}
	}
	else
	{
		hashtable[index] = new hashNode<K>(bucketSize);
		insertBucket = hashtable[index];
	}
	insertBucket->insertKey(key);

	return EXIT_SUCCESS;
}

template class Hashtable < uint32_t > ;