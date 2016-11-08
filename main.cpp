#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Buffer.h"
#include "NodeIndex.h"
#include "ListNode.h"
#include "Ptr.h"
#include "bfs.cpp"

using namespace std;

int main()
{

	ifstream myfile;
	string line;
	int pos = 0;
	int count, i, j, num[2];
	string type;
	string elem[3];
	string terminate = "S";
	myfile.open("tinyGraph.txt");
	string task[2] = { "A", "Q" };
	Buffer *bufferIn;
	Buffer *bufferOut;
	NodeIndex *indexIn;
	NodeIndex *indexOut;
	int n = 10;
	bufferIn = new Buffer(n, n);
	bufferOut = new Buffer(n, n);
	indexIn = new NodeIndex(n, n);
	indexOut = new NodeIndex(n, n);

	while (getline(myfile, line))
	{
		count = 0;
		while ((pos = line.find(" ")) != string::npos)
		{
			if (count >= 2)
			{
				cout << "Too many elements in line" << endl;
				myfile.close();
				return 1;
			}
			elem[count] = line.substr(0, pos);
			count++;
			line.erase(0, pos + 1);
		}
		if (count >= 2)
		{
			cout << "Too many elements in line" << endl;
			myfile.close();
			return 1;
		}
		if (count == 0)
		{
			if (line.compare(terminate))
			{
				cout << "Too few elements in line" << endl;
				myfile.close();
				return 1;
			}
			else
				break;
		}
		elem[count] = line;
		for (i = 0; i <= count; i++)
		{
			for (j = 0; j < elem[i].length(); j++)
			{
				if (isdigit(elem[i][j]) == 0)
				{
					cout << "Second and third elements must be integers" << endl;
					myfile.close();
					return 1;
				}
			}
			num[i] = atoi(elem[i].c_str());
		}
		/*Replace with code for insertion to graph*/
		indexOut->insertNode(num[0], num[1], *bufferOut);
		indexIn->insertNode(num[1], num[0], *bufferIn);
	}

	uint32_t *d;
	int e;

	for (j = 0; j < num[0]; j++)
	{

		d = indexOut->getNodeNeighbors(j, bufferOut);
		e = indexOut->getNoOfNeighbors(j, bufferOut);

		for (i = 0; i < e; i++)
		{
			cout << j << "->" << d[i] << endl;
		}

		d = indexIn->getNodeNeighbors(j, bufferIn);
		e = indexIn->getNoOfNeighbors(j, bufferIn);
		for (i = 0; i < e; i++)
		{
			cout << j << "<-" << d[i] << endl;
		}

	}

	myfile.open("tinyWorkload_FINAL.txt");
	terminate = "F";

	while (getline(myfile, line))
	{
		count = 0;
		while ((pos = line.find(" ")) != string::npos)
		{
			if (count >= 3)
			{
				cout << "Too many elements in line" << endl;
				myfile.close();
				return 1;
			}
			elem[count] = line.substr(0, pos);
			count++;
			line.erase(0, pos + 1);
		}
		if (count >= 3)
		{
			cout << "Too many elements in line" << endl;
			myfile.close();
			return 1;
		}
		if (count == 1)
		{
			cout << "Too few element in line" << endl;
			myfile.close();
			return 1;
		}
		if (count == 0)
		{
			if (line.compare(terminate))
			{
				cout << "Too few elements in line" << endl;
				myfile.close();
				return 1;
			}
			else
				continue;
		}
		elem[count] = line;
		type = elem[0];
		if ((type != task[0]) && (type != task[1]) && (type != terminate))
		{
			cout << "First element in a line must be A or Q" << endl;
			myfile.close();
			return 1;
		}
		for (i = 1; i <= count; i++)
		{
			for (j = 0; j < elem[i].length(); j++)
			{
				if (isdigit(elem[i][j]) == 0)
				{
					cout << "Elements in every line except the last must be integers" << endl;
					myfile.close();
					return 1;
				}
			}
			num[i - 1] = atoi(elem[i].c_str());
		}
		cout << "Task " << type << ": " << num[0] << "->" << num[1] << endl;
		if(type == task[0]){
			indexOut->insertNode(num[0],num[1],*bufferOut);
			indexIn->insertNode(num[1],num[0],*bufferIn);
		}
		if(type == task[1]){
			cout << bidirectionalBFS(num[0],num[1],indexIn,indexOut,bufferIn,bufferOut) << endl;
		}
	}


	delete bufferIn;
	delete bufferOut;
	delete indexIn;
	delete indexOut;
	return 0;
}
