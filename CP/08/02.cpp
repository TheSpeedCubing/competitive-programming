#include <iostream>
using namespace std;

int f, t, n, i, pos[1024];
int main() {
    string s[1024];
    cin >> t;
    while(t--){
        if(f++) cout <<"\n";
        
        cin >> n;
        
        i = 0;
        while(i<n)
          cin >> pos[i++];
        
        i = 0;
        while(i<n)
          cin >> s[i++];
        
        i = 0;
        while(i<n)
          cout <<s[pos[i++]]<<"\n";
    }
}
