#include <iostream>

using namespace std;

int isPrime(int l) {
  if (l < 2 || ((l & 1) == 0 && l != 2))
    return 0;
  for (long i = 3; i * i <= l; i += 2)
    if (l % i == 0)
      return 0;
  return 1;
}

int main()
{
	int T;
	cin >> T;
	for(int i = 1;i<=T;i++) {
		cout << "Case "<<i<<": ";
		string s;
		cin >> s;
		
		int result[128] = {0};
		for(char c : s) {
			result[c]++;
		}
		
		bool flag = 0;
		for(char c = '0';c<='z';c++){
			if(isPrime(result[c])){
				cout << c;
				flag = 1;
			}
		}
		cout << (flag ? "\n" : "empty\n");
	}
}
