// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL primeSize = 2000000;

bool prime[2000000];

vector<LL> almostprime;

int main() {
    
    //prime table
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    
    for(LL i = 2;i <= sqrt(primeSize);i++) {
        if(prime[i]) {
            for(LL j = i * i; j < primeSize; j += i) {
                prime[j] = false;
            }
        }
    }
    
    //almostprime table
    for(LL i = 2;i < primeSize;i++) {
        if(prime[i]) {
            LL k = i * i;
            while(k < 1e12) {
                almostprime.push_back(k);
                k *= i; 
            }
        }
    }
    
    sort(almostprime.begin(), almostprime.end());
    
    LL t, l, h;
    cin >> t;
    while(cin >> l >> h) {
        int count = 0;
        for(int i = 0;i < almostprime.size();i++) {
             if(almostprime[i] <= h && almostprime[i] >= l) {
                 count++;
             }
        }
         cout << count <<"\n";
    }
}
