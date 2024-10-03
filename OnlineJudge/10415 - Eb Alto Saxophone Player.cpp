#include <bits/stdc++.h>

using namespace std;

int main() {
	map<char,set<int>> m;
	
	m['c'] = {2,3,4,7,8,9,10};
	m['d'] = {2,3,4,7,8,9};
	m['e'] = {2,3,4,7,8};
	m['f'] = {2,3,4,7};
	m['g'] = {2,3,4};
	m['a'] = {2,3};
	m['b'] = {2};
	m['C'] = {3};
	m['D'] = {1,2,3,4,7,8,9};
	m['E'] = {1,2,3,4,7,8};
	m['F'] = {1,2,3,4,7};
	m['G'] = {1,2,3,4};
	m['A'] = {1,2,3};
	m['B'] = {1,2};
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		getline(cin,s);
		
		int arr[10] = {};
		
		int pressed[10] = {};
		
		for(char c : s) {
			for(int i = 1;i<=10;i++) {
			    if(m[c].count(i)) { //if need to press
				    if(!pressed[i-1]) { //keypress
				        arr[i-1]++;
				        pressed[i-1] = 1;
				    }
				} else { //keyrelease
						pressed[i-1] = 0;
					}
			}
		}
		
		for(int i = 0;i<10;i++) {
			if(i == 9) {
				cout << arr[i] << '\n';
			} else
				cout << arr[i] << " ";
		}
	}
}
