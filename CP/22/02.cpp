#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	char c;
	int left = 0;
	int i = 1;
	while(cin >> c) {
		 v.insert(v.begin() + left,i);
		 if(c == 'L') {
		 	 left++;
		 }
		 i++;
	}
	for(int j = 0;j<v.size();j++){
		cout << v[j] <<"\n";
	}
}
