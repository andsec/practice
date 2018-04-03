#include <vector>
#include <iostream>
using namespace std;

void swap(int dex1, int dex2, vector<int> &vec){
	//items to be swapped are passed in
	int temp = vec[dex1];
	vec[dex1] = vec[dex2];
	vec[dex2] = temp;
}

int partition(int left, int right, int pivot, vector<int> &vect){
	int leftPtr = left - 1;
	int rightPtr = right + 1;
	while(true){
		//the preeceding loops will iterate through list until
		//an item is found on the wrong side of the pivot
		while(leftPtr < right && vect[++leftPtr] < pivot);
		while(rightPtr > left && vect[--rightPtr] > pivot);

		//this condition checks if all items have been sorted
		if(leftPtr >= rightPtr) {break;}

		//this condition calls the swap function in order to change 
		//postion of items around pivot
		else {swap(leftPtr, rightPtr, vect);}
	}
	//returns position of pivot
	return leftPtr;
}

int main(){
	vector<int> arr = {23,4,35,1,31,5,3,15,3254,6,16,62,25,51,35,13,5,7};
	partition(0, arr.size() - 1, 10, arr);
	for(int i=0;i<arr.size();++i) {cout << arr[i] << endl;}
	return 0;
}