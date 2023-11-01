#include <iostream>
#include <bitset>
using namespace std;

int main(){
	int testCase;
	while(cin >> testCase && testCase){
    unsigned k , result = 0,diffCnt = 0;
		while (testCase--) {
			cin >> k;
			result = result ^ k;
		}
		while(result){
			if(result&1)
				diffCnt++;
			result>>=1;
		}
		cout << diffCnt <<"\n";
	}
}
