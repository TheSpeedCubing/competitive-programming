#include <iostream>
#include <algorithm>
using namespace std;

// 這個「副程式」給你參考，可以呼叫。會用，就很簡單！
int diff(unsigned int a, unsigned int b, int r) {
    int d = 0;
    for (; a != b; a /= r, b /= r)
        if (a % r != b % r) d++;
        
    return(d);
}

// 寫你的程式，可以呼叫副程式！
// 不懂副程式，就不管它，可以不呼叫，自己寫！
int main()
{
	unsigned int a,b;
	while(cin >> a >>b){
		if(a == 0 && b ==0)
		return 0;
		cout << diff(a,b,10)<<" "<<diff(a,b,7)<<" "<<diff(a,b,4)<<"\n";
	}
    return 0;
}
