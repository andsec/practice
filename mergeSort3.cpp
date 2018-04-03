#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//function to do sorting
void merging(vector<int> &vts, vector<int> &ws, int lowPtr, int highPtr, int upper){
	int j = 0;
	int lower = lowPtr;
	int middle = highPtr-1;
	int n = upper - lower+1;

	while(lowPtr <= middle && highPtr <= upper){
		if(vts[lowPtr] < vts[highPtr]) {ws[j++] = vts[lowPtr++];}
		else {ws[j++] = vts[highPtr++];}
	}
	while(lowPtr <= middle) {ws[j++] = vts[lowPtr++];}
	while(highPtr <= upper) {ws[j++] = vts[highPtr++];}

	for(int i = 0; i < n; i++) {vts[lower + i] = ws[i];}
}

//function to divide array then sort
vector<int> recMergeSort(vector<int> &vecToSort, vector<int> &workSpace, 
									int lowerBound, int upperBound){
	//first we check for the base case
	if(lowerBound == upperBound) {return vecToSort;}

	//else we further divide the array recursively before calling for merge
	else {
		int mid = (lowerBound+upperBound)/2;

		recMergeSort(vecToSort, workSpace, lowerBound, mid);
		recMergeSort(vecToSort, workSpace, mid+1, upperBound);

		merging(vecToSort, workSpace, lowerBound, mid+1, upperBound);
	}
	return vecToSort;
}

int main(){
	vector<int> myVec = {234,232,5631,14,4,145,654,43,8,1};
	

	vector<int> work(myVec.size());

	vector<int> arr = recMergeSort(myVec, work, 0, 9);

	for(int k = 0; k < arr.size(); ++k){
		cout << arr[k] << endl; 
	}

	return 0;
}