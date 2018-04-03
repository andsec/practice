//DOES NOT WORK

#include "doubleLink.cpp"
#include <iostream>

using namespace std;

class Dlist{
private:
	Link* first;
	Link* last;

public:
	Dlist(){
		first = NULL;
		last = NULL;
	}
	~Dlist(){
		delete first;
		delete last;
	}
	bool isEmpty(){return first == NULL;}

//insertion at front of list
	void insertFirst(int data){
		Link* newLink = new Link(data);

		//if list is empty, last will point to new link
		//if not, make first link point to new link
		//(isEmpty()) ? last = newLink : first->previous = newLink;
		
		if(isEmpty()) {last = newLink;}

		else{
			first->previous = newLink;

			//new link will point to old first link
			newLink->next = first;

		}
		//first now points to new link
		first = newLink;

		//if there isnt one item in list update last
		/*if(newLink->next != NULL){
			Link* current = first;
			//while current->next doesnt point to end iterate through list 
			//when it does, update last
			while(current->next != NULL){
				current = current->next;
			}
			last = current;
		}*/
	}

//insertion at end of list
	void insertLast(int data){
		Link* newLink = new Link(data);

		//if list is empty, first points to new link
		if(isEmpty()){first = newLink;}

		//else, last link points to new link and
		//new link will point to the old last link
		else{
			last->next = newLink;
			newLink->previous = last;
		}

		//last points to new link
		last = newLink;
	}

//delete first link in list
	Link* deleteFirst(){
		//link to delete
		Link* temp = first;

		//if one item in list, last will point to NULL
		//otherwise link after one to be deleted will
		//not point to any previous link
		(first->next == NULL) ? last = NULL : first->next->previous = NULL;

		
		//if(first->next == NULL){last = NULL;}
		//else{first->next->previous = NULL;}

		//first will now point to next link
		first = first->next;

		return temp;
	}

//delete last link in list
//THIS METHOD FUCKS EVERYTHING UP
	Link* deleteLast(){
		//link to delete
		Link* temp = last;

		//if one item, make first point to NULL
		if(first->next = NULL){first = NULL;}

		//if not, make the link before last link
		//point to NULL
		else {
			last->previous->next = NULL;
		}
		//last will now point to previous link
		last = last->previous;

		return temp;
	}

//method to insert item after a certain link.
//will return true if spot was found
	bool insertAfter(int key, int data){
		Link* current = first;

		//iterate through list to find key return false if not found.
		//loop if current link does not contain correct key
		while(current->item != key){
			//go to next link
			current = current->next;

			//if at end of list with no key, return false
			if(current == NULL) {return false;}
		}

		//if found, create new link
		Link* newLink = new Link(data);

		//check if current points to NULL (end)
		if(current == NULL){
			//if it does have new link point to null
			//then have last point to new link
			newLink->next = NULL;
			last = newLink;
		}

		//if not make new link point to link after current
		else{newLink->next = current->next;}

		//make new link point to key link (previous)
		//and make previous (current) point to new link
		newLink->previous = current;
		current->next = newLink;

		return true;
	}

//method to delete a specific link given a key
	Link* deleteKey(int key){
		//first we iterate through the list to check if key is present
		Link* current = first;

		while(current->item != key){
			//move to the next item and if at end return NULL
			current = current->next;
			if(current == NULL) {return NULL;}
		}

		//if first item, make first point to next item
		if(current == first) {first = current->next;}

		//if last item, last point to previous link
		else if(current == last) {last = current->previous;}

		//if not make item previous to current point to item after key link
		//and make link after key point to link before key
		else {
			current->previous->next = current->next;
			current->next->previous = current->previous;
		}
		return current;
	}
	void displayForward(){
		cout << "First --> Last" << endl;
		Link* current = first;
		while(current != NULL){
			current->displayLink();
			current = current->next;
		}
	}
	void displayBackward(){
		cout << "Last --> First" << endl;
		Link* current = last;
		while(current != NULL){
			current->displayLink();
			current = current->previous;
		}
	}
};

int main(){
	Dlist* list = new Dlist();

	list->insertFirst(22);
	list->insertFirst(44);
	list->insertFirst(66);

	list->insertLast(11);
	list->insertLast(33);
	list->insertLast(55);

	list->displayForward();
	list->displayBackward();

	list->deleteFirst();
	list->deleteLast();
	list->deleteKey(11);

	list->displayForward();
	list->displayBackward();

	list->insertAfter(22, 77);
	list->insertAfter(33, 88);

	list->displayForward();
	list->displayBackward();

	return 0;
}