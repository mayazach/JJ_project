#include <iostream>
#include "Parse.h"
#include <string>

using namespace std;



int Parse::parseInput(string line, Edge& edge)
{
	string op;
	uint32_t node1 = 0, node2 = 0;
	string terminate = "S";
	/*an den exei teleiwsei to input*/
	if (line.compare(terminate))
	{
		istringstream ss(line);
		cout << line << endl;
		if ((ss >> node1).fail())
		{
			cerr << "Nodes should be positive integers." << endl;
			return EXIT_FAILURE;
		}

		if ((ss >> node2).fail())
		{
			cerr << "Nodes should be positive integers." << endl;
			return EXIT_FAILURE;
		}

		/*an h grammh exei parapanw stoixeia apo tous 2 kombous*/
		if ((line.find("\n") != string::npos) && (line.find(" ") != string::npos))
		{
			cerr << "Too many elements in line." << endl;
			return EXIT_FAILURE;
		}

		edge.setNode1(node1);
		edge.setNode2(node2);
		ss.clear();
		return EXIT_SUCCESS;
	}
	else
	{
		return 2;
	}

}




int Parse::parseWorkload(string line, Task& task)
{
	string type;
	uint32_t node1 = 0, node2 = 0;
	string terminate = "F";
	string tasks[2] = { "A", "Q" };

	/*an den exei teleiwsei to input*/
	if (line.compare(terminate))
	{
		istringstream ss(line);

		if ((ss >> type).fail() || (type != tasks[0] && type != tasks[1]))
		{
			cerr << "First element in a line must be A or Q." << endl;
			return EXIT_FAILURE;
		}

		if ((ss >> node1).fail())
		{
			cerr << "Nodes should be positive integers." << endl;
			return EXIT_FAILURE;
		}

		if ((ss >> node2).fail())
		{
			cerr << "Nodes should be positive integers." << endl;
			return EXIT_FAILURE;
		}

		/*an h grammh exei parapanw stoixeia*/
		if ((line.find("\n") != string::npos) && (line.find(" ") != string::npos))
		{
			cerr << "Too many elements in line." << endl;
			return EXIT_FAILURE;
		}

		task.setTask(type, node1, node2);

		return EXIT_SUCCESS;
	}
	else
	{
		return 2;
	}

}
