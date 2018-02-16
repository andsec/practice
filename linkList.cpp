#include "link.cpp"
#include "ListIterator.cpp"
#include <iostream>
using namespace std;

class LinkList{
friend ListIterator;
private:
	Link* first;

public:
	LinkList() {first = NULL;}
	~LinkList() {delete first;}

	Link* getFirst() {return first;}

	void setFirst(Link* f) {first = f;}

	bool isEmpty() {return first == NULL;}

	//method returns an iterator initialized with this list
	ListIterator getIterator() {
		return new ListIterator(this);
	}

	void displayList(){
		Link* current = first;
		while(current != NULL){
			current->displayLink();
			current = current->next;
		}
		cout << " ";
	}
};