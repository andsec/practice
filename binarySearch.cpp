#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int recFind(int searchKey, int lowerBound, int upperBound, vector<int> &vec){
	int curIn;

	curIn = (upperBound + lowerBound)/2;
	if(vec[curIn] == searchKey){return curIn;}
	else if(lowerBound > upperBound){
		return vec.size();
	}
	else{
		if(vec[curIn] < searchKey){
			return recFind(searchKey, curIn + 1, upperBound, vec);
		}
		else{
			return recFind(searchKey, lowerBound, curIn - 1, vec);
		}
	}
}

void displayVec(vector<int> vec){
	for(int i = 0; i < vec.size() - 1; ++i){
		cout << vec[i] << endl;
	}
}

int main(){
	vector<int> myVec(100);

	generate(myVec.begin(), myVec.end(), rand);

	sort(myVec.begin(), myVec.end());

	int searchKey = 2089018456;

	if(recFind(searchKey, 0, myVec.size() - 1, myVec) != myVec.size()){
		cout << "searchKey found" << endl;
	}
	else {cout << "cannot find" << endl;}
}