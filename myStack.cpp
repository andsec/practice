#include <iostream>
using namespace std;

//my implementation of a basic stack class.
class myStack{
private:
//variable n holds nummber of buckets in stack.
//top holds the last position data is stored.
//stackArray will store all values
	int size;
	int n;
	int top;
	int* stackArray;
public:
	//Constructor
	myStack(int j){
		size = j;
		top = -1;
		stackArray = new int[size];
		n = 0;
		cout << "Constructor invoked" << endl;
	}
	//Destructor
	~myStack(){
		cout << "destructor invoked" << endl;
		delete stackArray;
	}
	//push adds items to top of stack
	void push(int item){
		stackArray[++top] = item;
	}
	//pop removes item from top of stack and returns to user
	int pop(){
		return stackArray[top--];
	}
	//peek allows the user to view top item in stack
	int peek(){
		return stackArray[top];
	}
	//ifEmpty returns true if top is -1
	bool ifEmpty(){
		return top == -1;
	}
	//ifFull returns true if the stack is full
	bool ifFull(){
		return top == n-1;
	}
	//displays all items to the top of the stack
	void display(){
		for(int g = 0; g < top+1; ++g){
			cout << stackArray[g] << endl;
		}
	}
};

int main(){
	myStack newStack(4);
	newStack.push(20);
	newStack.push(40);
	newStack.push(60);
	newStack.push(80);

	newStack.display();

	int hold = newStack.peek();
	cout << hold << " top value"<< endl;

	newStack.pop();
	newStack.display();
	return 0;
}