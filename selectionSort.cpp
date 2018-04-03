#include <iostream>

using namespace std;

int selectionSort(int* arr, int nElem){
	int min; int temp;

	for(int out = 0; out < nElem - 1; ++out){
		min = out;

		for(int in = out + 1; in < nElem; ++in){
			if(arr[in] < arr[min]){
				min = in;
				temp = arr[out];
				arr[out] = arr[min];
				arr[min] = temp;
			}
		}
	}
	return 0;
}

int main(){
	int len = 8;
	int array[] = {3,5,65,6,7,2,1,7};
	selectionSort(array, len);

	for (int p = 0; p < len; ++p) {
		std::cout << array[p] << endl;
	} 
}