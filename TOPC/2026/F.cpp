#include <bits/stdc++.h>
using namespace std;

struct Edge{
    long long tg, t, h;
};

int main(){
    long long n, m, u, v;
    cin>>n>>m;
    
    vector<vector<Edge>> g(n+1);
    
    while(m--){
        long long t, h;
        cin>>u>>v>>t>>h;
        g[u].push_back({v, t, h});
        g[v].push_back({u, t, h});
        
    }
    
    vector<long long> latest(n+1, -2E18);
    priority_queue<pair<long long, long long>> pq;
    
    latest[1] = 2E18;
    pq.push({2E18, 1});
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        if(a.first >= latest[a.second]){
            for(auto edge : g[a.second]){
                long long r = min(a.first,edge.h) - edge.t;
                if(r >latest[edge.tg]){
                    latest[edge.tg] = r;
                    pq.push({r, edge.tg});
                }
            }
        }
    }
    
    string s = "";
    for(int i=1; i<=n; i++){
        if(latest[i] >= 0){
            s += '1';
        }else s+= '0';
    }
    
    cout<<s<<endl;
    
    return 0;
}