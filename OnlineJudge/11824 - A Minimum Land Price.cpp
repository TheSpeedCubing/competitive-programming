#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		vector<int> arr;
		while(cin >> n && n != 0){
		  arr.push_back(n);
		}
		
		sort(arr.begin(),arr.end(), greater<int>());
		
		long long sum = 0;
		int ex = 1;
		for(int i : arr) {
			 sum += (2 * pow(i,ex));
		   ex++;
		}
		
		if(sum > 5000000)
		  cout << "Too expensive\n";
		else 
		  cout << sum <<"\n";
	}
}
