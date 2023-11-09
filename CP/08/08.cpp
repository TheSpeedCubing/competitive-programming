#include <iostream>

using namespace std;

int main()
{
	unsigned long long a = 0;
	char c;
	while(scanf("%c",&c) != EOF){
		if(isdigit(c)) {
		  if(a && a*10 / a != 10) {
		    a = c - 48;
		    cout << "\n";
		  } else  {
		    a = a * 10 + c - 48;
		  }
		  cout << c;
		}
	}
	cout <<"\n";
}
