#include <iostream>
#include "queue.h"

using namespace std;

Queue::~Queue(){
	while(head != NULL){
		QueueNode *n = head->next;
		delete head;
		head = n;
	}
}

void Queue::push(int id,int father){
	QueueNode **n=&head;
	while(*n != NULL)
		n=&((*n)->next);
	*n= new QueueNode(id,father);
	size++;
}

void Queue::print(){
	QueueNode *n=head;
	while(n!=NULL){
		cout << n->data.id << " child of " << n->data.father << ",";
		n=n->next;
	}
	cout << endl;
}

int Queue::pop(){
	QueueNode *n;
	n=head;
	head=head->next;
	size--;
	return n->data.id;
}

bool Queue::member(int num){
	QueueNode *n=head;
	while(n!=NULL){
		if(n->data.id == num)
			return true;
		n=n->next;
		}
	return false;
}

int Queue::getFather(int num){
	QueueNode *n=head;
	while(n!=NULL){
                if(n->data.id == num)
                        return n->data.father;
                n=n->next;
                }
        return -2;
}

int Queue::compare(Queue &q){
	QueueNode *n=head;
	while(n!=NULL){
		if(q.member(n->data.id))
			return n->data.id;
		n=n->next;
	}
	return -1;
}

int Queue::front(){
	if(head!=NULL)
		return head->data.id;
	else
		return -1;
}
