#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ItsSoFuckingLong;

ItsSoFuckingLong P(ItsSoFuckingLong A, ItsSoFuckingLong B) {
    if(A < B) 
      return 0;
      
    ItsSoFuckingLong t = 1, 
             i = A - B + 1;
    while(i <= A) {
    	 t *= i++;
    }
    return t;
}

ItsSoFuckingLong F(ItsSoFuckingLong N) {
    if(N == 0) 
      return 0;
    
    vector<ItsSoFuckingLong> digit;
    
    ItsSoFuckingLong temp = N;
    while(temp) {
    	 digit.push_back(temp % 10);
    	 temp /= 10;
    }
    
    reverse(digit.begin(), digit.end());
    
    bool used[12] = {0};

    ItsSoFuckingLong size = digit.size(), 
             result = 1, 
             i = 1;
    while(i < size) {
      result += P(10, size - i) - P(9, size - 1 - i);
    	i++;
    }
    
    i = 0;
    while(i < size) {
        for(int j = 0;j < digit[i];j++) {
            if((i || j) && !used[j] && 10 > i) 
              result += P(9 - i, size - i - 1);
        }
        
        if(used[digit[i]])
          break;
          
        used[digit[i]] = 1;
        i++;
    }
    return result;
}

int main() {
    ItsSoFuckingLong l, r;
    while(cin >> l >> r) {
        cout << F(r + 1) - F(l) << "\n";
    }
}
