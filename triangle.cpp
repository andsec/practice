#include <iostream>
using namespace std;

int triangle(int n){
	if(n == 1) {return 1;}
	else {return n + triangle(n - 1);}
}

int main(){
	cout << "Welcome to the Triangle App!" << endl;
	cout << "Please enter an integer" << endl;
	int n;
	cin >> n;

	while(n < 1){
		cout << "Please enter a valid input: ";
		cin >> n;
	}

	int ans = triangle(n);

	cout << "Here is your answer! " << ans << endl;
	return 0;
}