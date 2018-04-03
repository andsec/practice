#include <iostream>
using namespace std;
// this is a horrible insertion sort. DON'T USE THIS
void insertionSort(int arr[], int length)
{
	for(int j = 1; length - 1 > j; ++j)
	{
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
	for (int p = 0; p < length; ++p)
	{
		cout << arr[p] << endl;
	}
}

int main()
{
	int myArr[] = {5,2,4,6,1,3};
	int len = 6;
	insertionSort(myArr, len);
	return 0;
}