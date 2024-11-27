#include <iostream>
using namespace std;

int main() {
    string s, o;
	  
    long long a, b;
    while (getline(cin, s)) {
        cin >> o >> a >> b;
        cin.ignore();
        if(!b && o == "/")
          cout << "division by zero\n";
        else cout << (o=="+"?a+b:(o=="-"?a-b:o=="*"?a*b:a/b)) <<"\n";
    }
}
