#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

vector<int> shellSort(vector<int> &vec){
	int inner, outer, temp;
	int h = 1;

	//partition is based on size of vector
	while(h <= (vec.size()/3)) {h = h*3 + 1;}
	while(h>0){
		for(outer = h; outer<vec.size(); outer++){
			temp = vec[outer];
			inner = outer;
			while(inner > h-1 && vec[inner-h] >= temp){
				vec[inner] = vec[inner-h];
				inner -= h;
			}
			vec[inner] = temp;
		}
		h = (h-1)/3;
	}
	return vec;
}

int main(){
	vector<int> arr(100000000);
	generate(arr.begin(), arr.end(), rand);
	auto t1 = std::chrono::high_resolution_clock::now();
	shellSort(arr);
	auto t2 = std::chrono::high_resolution_clock::now();
	cout << "This algorithim took: "
		 << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
		 << " milliseconds" << endl;
	return 0;
}