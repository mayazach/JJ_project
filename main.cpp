#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Buffer.h"
#include "NodeIndex.h"
#include "bfs.h"


using namespace std;

int main(int argc, char* argv[])
{

	ifstream myfile;
	string line = "";
	string type;
	
	string tasks[2] = { "A", "Q" };
	Buffer *bufferIn;
	Buffer *bufferOut;
	NodeIndex *indexIn;
	NodeIndex *indexOut;
	int n = 100, retVal = 0,bucketSize=500;

	if (argc < 3)
	{
		cout << "Not enough arguments!" << endl;
		return EXIT_FAILURE;
	}

	char* filename = argv[1];
	char* workload = argv[2];




	myfile.open(filename);

	bufferIn = new Buffer(n, bucketSize);
	bufferOut = new Buffer(n, bucketSize);
	indexIn = new NodeIndex(n, n);
	indexOut = new NodeIndex(n, n);

	Parse parser;
	Edge edge;
	/*an to arxeio den anoikse*/
	if (myfile.fail() == true)
	{
		cerr << "Unable to open the input file " << filename << endl;
		return EXIT_FAILURE;
	}
	else /*diabasma arxeiou*/
	{

		while (getline(myfile, line))
		{
			retVal = parser.parseInput(line, edge);
			if (retVal == EXIT_FAILURE)
			{
				myfile.close();
				return retVal;
			}
			else if (retVal == EXIT_SUCCESS) /*eisagwgh sto grafo*/
			{
				indexOut->insertNode(edge.getNode1(), edge.getNode2(), *bufferOut);
				indexIn->insertNode(edge.getNode2(), edge.getNode1(), *bufferIn);
			}

		}

		
		myfile.close();

		myfile.open(workload);


		Task task;

		while (getline(myfile, line))
		{

			retVal = parser.parseWorkload(line, task);

			if (retVal == EXIT_FAILURE)
			{
				myfile.close();
				return retVal;
			}
			else if (retVal == EXIT_SUCCESS) /*ektelesh task*/
			{
				type = task.getType();
				if (type == tasks[0])
				{
					indexOut->insertNode(task.getNode1(), task.getNode2(), *bufferOut);
					indexIn->insertNode(task.getNode2(), task.getNode1(), *bufferIn);
				}
				if (type == tasks[1])
				{
			//		cout << bidirectionalBFS(task.getNode1(), task.getNode2(), indexIn, indexOut, bufferIn, bufferOut) << endl;
				}
			}

		}

		delete bufferIn;
		delete bufferOut;
		indexIn->clean();
		indexOut->clean();
		delete indexIn;
		delete indexOut;

		return EXIT_SUCCESS;
	}

}