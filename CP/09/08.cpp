#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long m,n;
	while(cin >> m>>n){
    string s = bitset<32>(m).to_string();
    while(n--) {
      string s2;
      for(int i = 0;i<16;i++)
      	s2 = s2 + s[i+16] + s[i];
    	s = s2;
    }
    cout << bitset<32>(s).to_ulong() << "\n";
	}
}
