#include <bits/stdc++.h>

using namespace std;


int main()
{
    // time, q, period
    set<tuple<int,int,int>> s;
    
    int q, p;
    string str;
    while(cin >> str && str != "#") {
        cin >> q >> p;
        s.insert({p, q, p});
    }

    int k;
    cin >> k;
    while(k--) {
        tuple<int,int,int> t = *s.begin();
        s.erase(s.begin());
        
        cout << get<1>(t) << "\n";
        
        get<0>(t) += get<2>(t);
        s.insert(t);
    }
}
