#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
#include <stdint.h>


using namespace std;
class Task
{

private:
	string type;
	uint32_t node1;
	uint32_t node2;

public:

	void setTask(string t, uint32_t n1, uint32_t n2)
	{
		type = t;
		node1 = n1;
		node2 = n2;
	}


	uint32_t getNode1()
	{
		return node1;
	}

	uint32_t getNode2()
	{
		return node2;
	}


	string getType()
	{
		return type;
	}

	Task() :type(""),node1(0), node2(0) {}
};






#endif