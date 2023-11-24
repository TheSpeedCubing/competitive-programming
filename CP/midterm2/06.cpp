#include <iostream>
using namespace std;
// 用 long long 讀資料
// 這等於處理 1000 進位～
// 你可以用 %03d 印出前導為0 的三位數數值
int main()
{
	long long n;
	while(cin >> n) {
		if(n == 0)
		cout << "0\n";
		else {
		string s;
	  int index = 0;
		while(n) {
			index++;
			s = (char) (n %10 + 48) + s;
			if(index % 3 == 0 && n / 10 != 0)
			  s = "," + s;
			n /= 10;
		}
		cout << s <<"\n";
	}}
}
