#include<iostream>
using namespace std;

//DOES NOT WORK
//function to split array then merge and sort the 2 halfs
int merge(int arr[], int len){
	int half = 4;
	int leftArr[4];
	int rightArr[4];
//add left half values to left array
	for(int i = 0; i < half - 1; ++i){
		leftArr[i] = arr[i];
	}
//add right half values to right array
	for(int j = 0; j < half - 1; ++j){
		rightArr[j] = arr[half + j];
	}
//merge the 2 smaller arrays back into the
//origional in ascending order.

//for loop to iterate through every position
//in the origional array.
	for(int k = 0; k < len - 1; ++k){
		if(leftArr[k] <= rightArr[k]){
			arr[k] = leftArr[k];
		}
		if(rightArr[k] < leftArr[k]){
			arr[k] = rightArr[k];
		}
	}
	return 0;
}
// in the mergesort function, recursive
// calls are made in order to split arrays
// continuously until one element is left
// in each array then the arrays will sort

void mergeSort(int arr[], int t, int len){
	int newlen = len - 1;
	if(t < newlen){
		int q = (len + t)/2;
		mergeSort(arr, t, q);
		mergeSort(arr, q + 1, len);
		merge(arr, len);
	}
}

int main(){
	int arr[] = {5,2,4,7,1,3,2,6};
	int len = 8;

	mergeSort(arr, 0, len);

	for (int p = 0; p < len; ++p) {
	std::cout << arr[p] << endl;
}
	return 0;
}