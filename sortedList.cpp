#include "link.cpp"
#include <iostream>
using namespace std;

class SortedList{
private:
	Link* first;
	
public:
	SortedList(){
		first = NULL;
	}

	bool isEmpty(){
		return first == NULL;
	}
//method to insert on insertion
	void insert(int data){
		//new link is first created
		Link* newLink = new Link(data);

	//two postion pointers are created to keep track
	//of where new link can possibly enter list.
		Link* previous = NULL;
		Link* current = first;

	//we loop through the list for a potential postion
	//until either current points to the end of the list
	//or new data item is less than the next position

		while(current != NULL && data > current->item){
			//when both conditions are met, position
			//pointers are shifted to next item

			previous = current;
			current = current->next;
		}

	//in case of new data item is smaller than
	//all items on the list
		if(previous == NULL){
			first = newLink;
		}
	//otherwise not at beginning
		else{
			previous->next = newLink;
		}

	//new link now points to next link in proper position
		newLink->next = current;
	}
//method to remove and return first item on list
	Link* remove(){
		Link* temp = first;
		first = first->next;
		return temp;
	}

	void displayList(){
		Link* temp = first;
		while(temp != NULL){
			cout << temp->item << endl;
			temp = temp->next;
		}
		cout << "end" << endl;
	}
};

int main(){
	SortedList* list = new SortedList();

	list->insert(20);
	list->insert(40);

	list->displayList();

	list->insert(10);
	list->insert(30);
	list->insert(50);

	list->displayList();

	list->remove();

	list->displayList();
}