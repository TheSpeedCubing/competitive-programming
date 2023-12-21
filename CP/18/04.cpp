#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int i;
	cin >> i;
	cin.ignore();
	
	string str;
	while(getline(cin,str)) {
	  set<string> sets;
	  stringstream iss(str);
	  string s;
	  while(iss >> s)
	    sets.insert(s);
	    
	  bool first = 0;
	  for(string str : sets){
	  	if(first++)
	  	  cout <<" ";
		  cout << str;
	  }
	  cout <<"\n";
	}
}