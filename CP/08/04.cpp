#include <iostream>
using namespace std;

int main() {
    char buffer[1024];
    while(cin.getline(buffer, 1024, ',')){
       	cout << buffer <<" ";
		    cin.ignore(1024,',');
		    cin.ignore(1024,',');
        int a, t=5;
        while(t--) {
        	  cin >> a;
            cout << "FFFFFFDCBAA"[a/10] << (t ? "":"\n");
	      		cin.ignore(1024, t ? ',' : '\n');
        }
    }
}