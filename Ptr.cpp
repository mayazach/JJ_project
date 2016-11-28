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

	if (hashtable == NULL)
	{
		hashtable = new Hashtable<uint32_t>(size);

		if (hashtable == NULL)
		{
			cerr << "Hashtable: Memory allocation error." << endl;
		}
	}
	int ret= hashtable->insert(node);
	return ret;

}






/*************************************/

