#include <bits/stdc++.h>

using namespace std;

int cnt, size, f, i;

int main() {
	
    while (cin >> cnt >> size) {
        double dist[1024] = {};
      
        if(f++) cout << "\n";
         
        i = cnt;
        while(i--) {
            dist[i-1] = dist[i] + size / 2.0 / i;
        }
        
        for(i = 0;i < cnt;i++) {
            cout << *(new string(floor(dist[i]),' ')) 
                 << *(new string(size,'*')) 
                 <<"\n";
        }
    }
}
