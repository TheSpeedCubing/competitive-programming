#include <iostream>
using namespace std;
int main()
{
    // 提示：每個位數先記到陣列去，再倒著印出來！
    // Put your code below
    int a,b;
    while(cin >> a>> b && (a!=0&&b!=0)){
    	 string s = "";
    	 while(a) {
    	 	  s+= ((a%b) + 48);
    	 	  a/=b;
    	 }
    	 for(int i = s.length()-1;i>=0;i--){
    	 	cout << s[i];
    	 }
    	 cout <<"("<<b<<")\n";
    }
    
    return 0;
}
