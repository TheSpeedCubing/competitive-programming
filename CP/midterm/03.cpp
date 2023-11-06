#include <iostream>

using namespace std;

int main()
{
	int a;
	cin >>a;
	while(a--){
		int h,m,s;
	  cin >> h;
	  cin.ignore();
	  cin >> m;
	  cin.ignore();
	  cin >> s;
	  cout <<(s+m*60+h*3600)<<"\n";
	}
}