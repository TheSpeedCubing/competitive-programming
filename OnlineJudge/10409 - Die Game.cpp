#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while(cin >> n && n) {
		cin.ignore();
		string s;
		
		int arr[] = {1,6,2,3,5,4};
		
		int f[4][4] = {{0,4,1,2},{0,2,1,4},{0,3,1,5},{0,5,1,3}};
		while(n--) {
		    getline(cin,s);
		  
		    int x;
		    if(s == "north") {
			    x = 0;
		    }
		    if(s == "south") {
		  	    x = 1;
		    }
		    if(s == "east") {
		    	x = 2;
		    }
		    if(s == "west") {
			    x = 3;
		    }
			
			int t = arr[f[x][0]];
			arr[f[x][0]] = arr[f[x][1]];
			arr[f[x][1]] = arr[f[x][2]];
			arr[f[x][2]] = arr[f[x][3]];
			arr[f[x][3]] = t;
		}
		
		cout << arr[0] << "\n";
	}
}
