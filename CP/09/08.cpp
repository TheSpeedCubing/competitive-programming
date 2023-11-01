#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

int main()
{
	long long m,n;
	while(cin >> m>>n){
    string s = bitset<32>(m).to_string();
    while(n--) {
      stringstream ss;
      for(int i = 0;i<16;i++)
      	ss << s[i+16] << s[i];
    	s = ss.str();
    }
    cout << bitset<32>(s).to_ulong() << "\n";
	}
}
