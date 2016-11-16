#include <iostream>
#include <cstdlib>
#include "queue.h"
#include "NodeIndex.h"
#include "Buffer.h"
#include "bfs.h"

using namespace std;

int bidirectionalBFS(int start, int finish,NodeIndex *in,NodeIndex *out,Buffer *buffin,Buffer *buffout)
{
	Queue frontier1,frontier2,explored;
	int node1,node2,father1,father2;
	uint32_t *successors;
	int size,i,comp;

	if(start == finish)
		return 0;

	node1=start;
	node2=finish;
	father1=start;
	father2=finish;
	explored.push(node1);
	explored.push(node2);

	successors = out->getNodeNeighbors(node1,buffout);
	if(successors == NULL){
		return -1;
	}
	size = out->getNoOfNeighbors(node1,buffout);
	for(i=0;i<size;i++){
		if(successors[i] == node2){
			return 1;}
		frontier1.push(successors[i],node1);
	}
	successors =in->getNodeNeighbors(node2,buffin);
	if(successors == NULL){
                return -1;
        }
        size = in->getNoOfNeighbors(node2,buffin);
	for(i=0;i<size;i++){
		frontier2.push(successors[i],node2);
	}
	if(frontier1.compare(frontier2) != -1)
		return 2;

	while((!frontier1.isEmpty()) && (!frontier2.isEmpty())){
		node1=frontier1.pop();
		node2=frontier2.pop();
		explored.push(node1,father1);
		explored.push(node2,father2);
		successors = out->getNodeNeighbors(node1,buffout);
	        size = out->getNoOfNeighbors(node1,buffout);
	        for(i=0;i<size;i++){
	                if(successors[i] == node2)
	                        return getPathSize(node1,father2,explored);
			if((!frontier1.member(successors[i])) && (!explored.member(successors[i])))
		                frontier1.push(successors[i],node1);
	        }
		successors=in->getNodeNeighbors(node2,buffin);
	        size = in->getNoOfNeighbors(node2,buffin);
	        for(i=0;i<size;i++){
			if((!frontier2.member(successors[i])) && (!explored.member(successors[i])))
		                frontier2.push(successors[i],node2);
	        }
		comp = frontier1.compare(frontier2);
		if(comp != -1){
			return getPathSize(frontier1.getFather(comp),frontier2.getFather(comp),explored);
		}

		father1=frontier1.getFather(frontier1.front());
		father2=frontier2.getFather(frontier2.front());
	}


	return 0;
}


int getPathSize(int father1,int father2,Queue &explored){
	int current,path=0;
	current=father1;
        path=1;
        current=explored.getFather(current);
        while(current != -1){
                path++;
                current = explored.getFather(current);
        }
        current=father2;
        path++;
        current=explored.getFather(current);
        while(current !=-1){
                path++;
                current = explored.getFather(current);
        }
	return path;
}
