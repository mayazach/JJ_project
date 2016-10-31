#include <iostream>
using namespace std;

class Queue{

struct Node{
	int s;
	Node *next;
	Node(int num,Node *point=NULL):s(num),next(point){
		cout << "Creating new node." << endl;}
};

	Node *head;
	int size;
public:
	Queue():head(NULL),size(0){cout << "Queue was just created." << endl;}
	~Queue(){
		while(head != NULL){
			Node *n = head->next;
			delete head;
			head = n;
		}
		cout << "Queue destroyed." << endl;
	}
	int getSize(){return size;}
	bool isEmpty(){
		if(head==NULL)
			return true;
		else
			return false;
	}
	void pushBack(int num){
	//add element num to the end of the queue
		Node **n=&head;
		while(*n != NULL)
			n=&((*n)->next);
		*n= new Node(num);
		size++;
	}
	void print(){
	//print all elements
		Node *n=head;
		while(n!=NULL){
			cout << n->s << " ";
			n=n->next;
		}
		cout << endl;
	}
	int pop(){
	//remove first element from queue and return
		Node *n;
		n=head;
		head=head->next;
		size--;
		return n->s;
	}
	bool member(int num){
	//check if num is already in the queue
		Node *n=head;
		while(n!=NULL){
			if(n->s == num)
				return true;
			n=n->next;
		}
		return false;
	}
	int front(){if(head!=NULL)return head->s;}//return first element
	int back(){
	//return last element
		Node *n=head;
		if(head!=NULL){
			while(n->next!=NULL)
				n=n->next;
			return n->s;
		}
	}
};
