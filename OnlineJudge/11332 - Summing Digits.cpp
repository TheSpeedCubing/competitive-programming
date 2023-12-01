#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        while(n > 9) {
            int sum = 0;
            int n2 = n;
            while(n2){
                sum += n2 % 10;
                n2 /= 10;
            }
            n = sum;
        }
        cout << n <<"\n";
    }
}
