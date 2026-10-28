#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v;
    long long w;
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<int> a(n), b(n);
  vector<long long> c(n);
  
  for(int &x : a){
      cin>>x;
      --x;
  }
  
  for(int &x : b){
      cin>>x;
      --x;
  }
  for(long long &x : c) cin>>x;

  vector<Edge> e;
  
  int S = n;
  
  for(int i=0; i<n; i++){
      e.push_back({S, i, c[i]});
      e.push_back({i, S, 0});
  }
  
  for(int i=0; i+1<n; i++) e.push_back({a[i], a[i+1], 0});
  
  for(int i=0; i+1<n; i++){
      int p = b[i], q = b[i+1];
      e.push_back({q, p, c[p]-c[q]});
  }
  
  vector<long long> d(n+1, 0);
  
  for(int i=0; i<=n; i++){
      bool changed =false;
      
      for(auto edge : e){
          int u = edge.u, v =edge.v;
          long long w = edge.w;
          
          if(d[v] > d[u] + w){
              d[v] = d[u] + w;
              changed = true;
              
              if(i == n){
                  cout<<"No"<<endl;
                  return 0;
              }
          }
      }
      if(!changed) break;
  }
  cout<<"Yes"<<endl;
}

