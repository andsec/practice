#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

void swap(int dex1, int dex2, vector<int> &vec){
	//items to be swapped are passed in
	int temp = vec[dex1];
	vec[dex1] = vec[dex2];
	vec[dex2] = temp;
}

int partitionIt(int left, int right, int pivot, vector<int> &vect){
	int leftPtr = left - 1;
	int rightPtr = right;
	while(true) {
		//the preeceding loops will iterate through list until
		//an item is found on the wrong side of the pivot
		while(vect[++leftPtr] < pivot);
		while(rightPtr > 0 && vect[--rightPtr] > pivot);

		//this condition checks if all items have been sorted
		if(leftPtr >= rightPtr) {break;}

		//this condition calls the swap function in order to change 
		//postion of items around pivot
		else {swap(leftPtr, rightPtr, vect);}
	}
	//this swap is to put pivot in correct position
	swap(leftPtr, right, vect);
	//returns position of pivot
	return leftPtr;
}

void recQuickSort(int left, int right, vector<int> &vectt){
	if(right-left <= 0) return;

	else {
		int pivot = vectt[right];

		int partition = partitionIt(left, right, pivot, vectt);
		recQuickSort(left, partition - 1, vectt);
		recQuickSort(partition + 1, right, vectt);
	}
}

int main(){
	vector<int> arr(100000000);
	generate(arr.begin(), arr.end(), rand);
	auto t1 = std::chrono::high_resolution_clock::now();
	recQuickSort(0, arr.size() - 1, arr);
	auto t2 = std::chrono::high_resolution_clock::now();
	cout << "This algorithim took: "
		 << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
		 << " milliseconds" << endl;
	return 0;
}