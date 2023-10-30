#include <iostream>
using namespace std;

int main() {
    char o,buffer[1024],c;
    long long a, b;
    while(cin.getline(buffer, 1024)){
        cin >> o >> a >> b>>c;
        if(!b && o =='/')
          cout << "division by zero\n";
        else cout << (o=='+'?a+b:(o=='-'?a-b:o=='*'?a*b:a/b)) <<"\n";
    }
}
