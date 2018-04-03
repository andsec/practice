#include <iostream>
using namespace std;

class Link {
public:
//2 variables to hold data of any object class
	int item;

//pointer to next link in list
	Link* next;

//pointer to previous link in list
	Link* previous;

	Link(int data){
		item = data;
	}

	~Link(){
		cout << "destructor invoked" << endl; 
		delete next;
		delete previous;
	}
//method displays current link
	void displayLink(){
		cout << "{ " << item << " }" << endl;
	}
};