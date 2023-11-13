#include <iostream>

using namespace std;

int main() {
    long long player, n, dt[1024];
    while(cin >> player >> n) {
    	
        long long total = 0, i = n, min = 1;
        while(i--){
            cin >> dt[i];
            total += dt[i];
        }
        total /= player;
        
        while(min <= total) {
        	
            long long average = (min + total) / 2,
                      maxPlayer = 0,
                      i = n;
            while(i--)
            	maxPlayer += dt[i] / average;
                
           maxPlayer >= player ? min = average + 1 : total = average - 1;
        }
        cout << total << "\n";
    }
}
