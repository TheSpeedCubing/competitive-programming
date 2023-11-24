#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long long in;
	while(cin >> in){
		if(in == 0){
			break;
		}
    while(1) {
    unsigned long long sum = 0;
		  while(in) {
		   sum += in % 10;
		   in /= 10;
		  }
		  if(sum < 10) {
        cout <<sum<<"\n";
		    break;
		  }
		  else in = sum;
    }
	}
}

