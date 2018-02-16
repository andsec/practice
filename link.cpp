#include <iostream>
using namespace std;


class Link {
public:
//2 variables to hold data of any object class
	int item;

//pointer to next link in list
	Link* next;

	Link(int item1){item = item1;}
	~Link(){delete next;}

//method displays current link
	void displayLink(){
		cout << " { " << item << " } " << endl;
	}
};