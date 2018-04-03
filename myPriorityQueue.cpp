#include <iostream>
using namespace std;

class MyPriQueue{
private:
//size holds amount of buckets in array.
//n is the number of items currently held.
	int size;
	int* queArr;
	int n;
public:
	MyPriQueue(int sizeOfArr){
		size = sizeOfArr;
		queArr = new int[size];
		n=0;
	}
	~MyPriQueue(){delete queArr;}
//insert will first check if array is empty. if it
//is then the item will be inserted into the first position.
//if not then item will be inserted at appropriate position
//while moving shifting items if necessary
	void insert(int item){
		int j; //where item will be inserted +1 after shifting 
		if(n == 0){
			queArr[n++] = item;
		}
		else {
//all elements in array will be shifted before
//the new elements is inserted
			for(j = n-1; j>=0; --j){
				if(item > queArr[j])
					queArr[j+1] = queArr[j];
				else break;
			}
			queArr[j+1] = item;
			++n;
		}
	}
	void display(){
		for(int g = 0; g < size; ++g){
			cout << queArr[g] << endl;
		}
	}
//there are many more methods needed but I am lazy
};

int main(){
	MyPriQueue quu(5);
	quu.insert(30);
	quu.insert(50);
	quu.insert(10);
	quu.insert(40);
	quu.insert(20);

	quu.display();
}