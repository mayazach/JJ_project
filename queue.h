#ifndef QUEUE_H_
#define QUEUE_H_

/*variable for storing the ids and fathers of the nodes in the queue*/
struct nodeInfo{
	int id;
	int father;
};

class Queue{

struct QueueNode{
	nodeInfo data;
	QueueNode *next;
	QueueNode(int id, int father){data.id=id;data.father=father;}
};

QueueNode *head;
int size;

public:
Queue(){head=NULL;size=0;};
~Queue();
int getSize(){return size;};
bool isEmpty(){return head==NULL;};

/*Adds node to the back of the queue.
*
*id: number of node to insert
*father: number of parent node, default is -1
*
*In BFS, we use push(id) for adding to the frontier and push(id,father) for adding to the explored set
*Node where BFS starts is added to explored with push(id)
*/
void push(int id,int father = -1);

/*Prints information about each node in the queue*/
void print();

/*Removes a node from the front of the queue and returns its id
*
*In BFS, only the ids of nodes popped from the frontier are important.
*Nodes in the explored set are not popped.
*/
int pop();

/*Returns true if input number matches the id of a node in the queue*/
bool member(int num);

/*Returns the father of a node in the queue whose id matches input number.
*If there is no such node, returs -2.
*/
int getFather(int num);

int front();

int compare(Queue &q);
};
#endif
