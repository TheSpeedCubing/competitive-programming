#include <iostream>
using namespace std;

int main(){
	string s, s2;
	cin >> s;
	int T;
	cin >> T;
	while(T--){
		cin >> s2;
		
		int j = 0, first = 0;
		bool found = 1;
		for(char c : s2){
			bool flag = 0;
			while(j<s.length() && !flag) {
				if(s[j] == c) {
					first = first ? first : j+1;
					flag = 1;
				}
				j++;
			}
			found = flag;
			if(!found)
			  break;
		}
		found ? cout << "yes "<<first<<" "<<j<<"\n" : 
		        cout <<"no\n";
	}
}