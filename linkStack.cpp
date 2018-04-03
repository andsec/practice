#include "myLinkedList.cpp"
#include <iostream>
using namespace std;

class LinkStack{
private:
	LinkedList* theList;

public:
	LinkStack(){
		theList = new LinkedList();
	}
	//method pushes item to the top of the stack
	void push(int data){
		theList->insertFirst(data);
	}
	//method returns top item on stack
	Link* pop(){
		return theList->deleteFirst();
	}
	bool Empty(){
		return theList->isEmpty();
	}
	void displayStack(){
		theList->displayList();
	}
};

int main(){
	LinkStack* stack = new LinkStack();

	stack->push(20);
	stack->push(40);

	stack->displayStack();

	stack->push(60);
	stack->push(80);

	stack->displayStack();

	stack->pop();
	stack->pop();

	stack->displayStack();

	return 0;
}
