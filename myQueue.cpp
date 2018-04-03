#include <iostream>
using namespace std;

class myQueue{
private:
	int size;
	int n;
	int* queArray;
	int front;
	int rear;
public:
	myQueue(int sizeOfArray){
		size = sizeOfArray;
		n = 0;
		queArray = new int[size];
		front = 0;
		rear = -1;
	}
	~myQueue(){
		delete queArray;
	}
//insert first checks if rear is not at end 
	void insert(int item){
		(rear == size-1)? rear=-1: queArray[++rear] = item;
		++n;
	}

	int remove(){
		int temp = queArray[front++];
		if(front == size-1) front = 0;
		--n;
		return temp;
	}
	int peek(){
		return queArray[front];
	}
};