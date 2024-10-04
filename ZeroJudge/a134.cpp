// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    
    v.push_back(0);
    v.push_back(1);
    
    int total = 0;
    while(true) { //init fibs
        int j = v[v.size()-1] + v[v.size()-2];
        v.push_back(j);
        total += j;
        if(j >= 100000000) {
            break;
        }
    }
    
    int t;
    cin >> t;
    int a;
    
    while(t--) {
        cin >> a;
        cout << a <<" = ";
        
        string s;
        int i = v.size()-1;
        bool start = false;
        while(true) {
            if(a >= v[i]) { //subtract
                start = true; //start appending zero
                
                a -= v[i];
                s += '1';
                
                if(a == 0) { //end
                    i -= 2; //remove the first two number
                    while(i--) {
                        s += '0';
                    }
                    break;
                }
                i--;
                s += '0';
            } else if(start) s += '0';
            
            i--;
        }
        cout << s <<" (fib)\n";
    }
}
