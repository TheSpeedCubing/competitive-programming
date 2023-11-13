#include <iostream>
#include <cstring>
using namespace std;

//cache to prevent TLE
bool cache[16777216]; //global var sized in stack mem!
int cnt[16777216], i = 2 , a , b;

int main() {

   memset(cache,1,16777216);
    
    while(i*i <=16777215){
        if(cache[i]) {
            for(int multiplier= 2*i ; multiplier <= 16777215 ; multiplier+=i) 
              cache[multiplier]=0;
        }
        i++;
    }
    
    i = 2;
    while(i <= 16777215) {
        cnt[i] = cnt[i-1] + cache[i];
        i++;
    }
        
    while(cin >> a >> b)
        cout << cnt[b] - cnt[a-1] << "\n";
}