#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int main() {
	int n,flag=1;
	while(cin >>n){
		if(flag)
		  flag=0;
		else cout <<"\n";
	    for(int i = 0;i<pow(2,n);i++){
	        cout << bitset<16>(i ^ (i >> 1)).to_string().substr(16-n)<<"\n";
	    }
	}
}