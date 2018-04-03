#include "myLinkedList.cpp"
#include <iostream>
using namespace std;

class LinkQueue{
private:
	LinkedList* theList;

public:
	LinkQueue(){
		theList = new LinkedList();
	}
	bool Empty(){
		return theList->isEmpty();
	}
	//method to insert item at end of queue
	void insert(int data){
		theList->insertLast(data);
	}
	//method removes item at front of queue and returns it
	Link* remove(){
		return theList->deleteFirst();
	}
	void displayQueue(){
		theList->displayList();
	}
};

int main(){
	LinkQueue* theQue = new LinkQueue();

	theQue->insert(20);
	theQue->insert(40);

	theQue->displayQueue();

	theQue->insert(60);
	theQue->insert(80);

	theQue->displayQueue();

	theQue->remove();
	theQue->remove();

	theQue->displayQueue();
}