#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int n;
	while(cin >> n && n != 0){
    cout <<"The parity of ";
    
    string s = bitset<32>(n).to_string();
    int cnt = 0;
    bool flag = 0;
    for(char c : s){
    	if(c == '1') {
    	  flag = 1;
    	  cnt++;
    	}
    	if(flag)
    	  cout << c;
    }
    cout <<" is "<<cnt<<" (mod 2).\n";
	}
}
