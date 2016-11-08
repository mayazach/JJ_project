#include <iostream>
#include "queue.cpp"

using namespace std;

int main(){
	//constructor test
	Queue example;
	Queue second;

	int num=4;

	//test if isEmpty returns true for empty queue
	if(example.isEmpty())
		cout << "Queue is empty." << endl;
	else
		cout << "Queue not empty." << endl;

	//push test
	example.push(4,3);

	//test if isEmpty returns false for not empty queue
	if(example.isEmpty())
                cout << "Queue is empty." << endl;
        else
                cout << "Queue not empty." << endl;

	example.push(5);
	example.push(8,2);

	//getSize() test
	cout << example.getSize() << " nodes in queue." << endl;

	//print() test
	example.print();

	//test if member(int num) can find if node with input id is in the queue
	//test if getFather(int num) can return the father of the node with input id
	if(example.member(num)){
		cout << num << " is in queue." << endl;
		cout << "It is the child of " << example.getFather(num) << endl;
	}
	else
		cout << num << " not in queue." << endl;

	num = 7;

	if(example.member(num))
                cout << num << " is in queue." << endl;
	else
                cout << num << " not in queue." << endl;

	second.push(4,3);
	second.push(9);
	second.push(11,9);
	second.push(8,2);
	second.print();

	cout << example.compare(second) << endl;
	second.print();

	cout << second.getFather(second.front()) << endl;

	//pop() test
	while(!example.isEmpty())
		cout << "Bye " << example.pop() << endl;
}
