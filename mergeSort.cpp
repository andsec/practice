#include<iostream>
using namespace std;
//THIS IS REALLY SHITTY. FIX
// just make one merge sort function
// always follow sudo code first. then make adjustments
//First divide array into 2 arrays, left and right

int divideArr(int arr[], int len){
	int half = len/2;
	int leftArr[half]; 
	int rightArr[half];
	for(int i = 0; i < half; ++i){
		leftArr[i] = arr[i];
	}
	for(int j = half + 1; j < len; ++j){
		rightArr[j] = arr[j];
	}
	//you cannot return 2 variables in C++ try using std::pair
	return leftArr[half], rightArr[half];
}

//Merge smaller arrays into larger array

int combine(int leftArr[], int rightArr[], int len){
	int le = 0;
	int arry[len];
	int re = 0;
	//fix this bullshit
	for(int e = 0; e < len; ++e){
		(leftArr[le] <= rightArr[re]) ? arry[e] = leftArr[le] : arry[e] = rightArr[re];
		(leftArr[le] <= rightArr[re]) ? ++le : ++re;
	}
	return arry[len];
} 
void printArr(int arr[]){
	for (int p = 0; p < 8; ++p) {
		std::cout << arr[p] << " ";
	}
}
int main(){
	int arr[] = {2,4,5,7,1,2,3,6};
	int len = 8;
	int lef[4];
	int rih[4];
	lef[4] , rih[4] = divideArr(arr,len);
	arr[8] = combine(lef,rih,8);
	printArr(arr);
	return 0;
}