#include "link.cpp"

class ListIterator;

class LinkList{

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

class ListIterator {
private:
	Link* current;
	Link* previous;
	LinkList ourList;

public:
	ListIterator(LinkList list){
		ourList = list;
		reset();
	}

	//method sets iterator to point at first item in list
	void reset() { 
		current = ourList.getFirst();
		previous = NULL;
	}

	bool atEnd() {
		return current->next == NULL;
	}

	void nextLink() {
		previous = current;
		current = current->next;
	}

	Link* getCurrent() {return current;}

	void insertAfter(int data) {
		Link* newLink = new Link(data);

		if(ourList.isEmpty()){
			ourList.setFirst(newLink);
			current = newLink;
		}
		else{
			newLink->next = current->next;
			current->next = newLink;
			reset();
		}
	}

	void insertBefore(int data) {
		Link* newLink = new Link(data);

		if(previous == NULL){
			newLink->next = ourList.getFirst();
			ourList.setFirst(newLink);
			reset();
		}
		else{
			newLink->next = previous->next;
			previous->next = newLink;
			current = newLink;
		}
	}

	int deleteCurrent() {
		int value = current->item;

		if(previous == NULL){
			ourList.setFirst(current->next);
			reset();
		}
		else {
			previous->next = current->next;
			if(atEnd()) {reset();}
			else{
				current = current->next;
			}
		}
		return value;
	}
};

