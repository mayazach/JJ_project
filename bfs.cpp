#include <iostream>
#include <cstdlib>
#include "queue.cpp"

using namespace std;

int getPathSize(int father1,int father2,Queue &explored);

int main(){
	Queue explored,frontier1,frontier2;
	int node1,node2,father1,father2;
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
