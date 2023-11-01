#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int T, cnt;
	cin >> T;
	while(T--){
		cin >> cnt;
		int c , copy = cnt;
		string s;
		while(cnt--) {
			 cin >> c;
			 s += bitset<8>(c).to_string();
		}
		cin >> cnt;
		cnt %= (copy*8);
		while(cnt<0)
			cnt+=copy*8;
			
		while(cnt--)
				s = s.substr(1) + s[0];
				
		while(copy--) {
				cout << bitset<8>(s.substr(0,8)).to_ulong()<< (copy?" ":"\n");
		    s = s.substr(8);
		}
	}
}
