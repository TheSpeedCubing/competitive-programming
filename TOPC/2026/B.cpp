#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    
    while(t--){
        int c, h, o;
        cin >> c >> h >> o;
        
        if(h == 2 * c - 4) cout <<"Saturated"<<endl;
        else cout<<"Unsaturated"<<endl;
    }
    return 0;
}