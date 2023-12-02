#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	while(cin >> N) {
		cin.ignore();
		vector<pair<string,string>> arr;
		string s, s2;
		for(int i = 0;i<N;i++){
		  getline(cin,s);
	  	getline(cin,s2);
		  arr.push_back(make_pair(s,s2));
		}
		int Q;
		cin >> Q;
		cin.ignore();
		while(Q--){
			getline(cin,s);
			for(pair<string,string> p : arr) {
				if(p.first == s){
					 cout << p.second <<"\n";
					 break;
				}
			}
		}
	}
}
