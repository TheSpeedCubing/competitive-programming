#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long VeryLong;

VeryLong P(VeryLong A, VeryLong B) {
    if(A < B) 
      return 0;
      
    VeryLong t = 1, 
             i = A - B + 1;
    while(i <= A){
    	 t *= i++;
    }
    return t;
}

VeryLong F(VeryLong N) {
    if(N == 0) 
      return 0;
    
    vector<VeryLong> digit;
    
    VeryLong temp = N;
    while(temp) {
    	 digit.push_back(temp % 10);
    	 temp /= 10;
    }
    
    reverse(digit.begin(), digit.end());
    
    bool used[12] = {0};

    VeryLong size = digit.size(), 
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
    VeryLong l = 0, r;
    while(cin >> l >> r) {
        cout << F(r + 1) - F(l) << "\n";
    }
}
