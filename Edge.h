#ifndef EDGE_H_
#define EDGE_H_
#include <stdint.h>

class Edge
{

private:
	uint32_t node1;
	uint32_t node2;

public:

	void setNode1(uint32_t n1)
	{
		node1 = n1;
	}

	void setNode2(uint32_t n2)
	{
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

	Edge() :node1(0), node2(0) {}


};


#endif