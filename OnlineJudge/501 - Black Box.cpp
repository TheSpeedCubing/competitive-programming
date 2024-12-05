#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  cin >> k;
  int f = 0;
  while (k--) {
    if(f++) cout << '\n';
    int m, n;
    cin >> m >> n;
    int m2 = m;
    
    priority_queue<int, vector<int>, greater<int>> left; // 1 2 3
    priority_queue<int> right; // 6 5 4
    
    int numbers[30001] = {};
    for(int i = 1;i<=m;i++) {
      cin >> numbers[i];
    }
    
    int cnt[30001] = {};
    int i;
    while(n--) {
      cin >> i;
      cnt[i]++;
    }
    
    for(int i = 1; i <= m2; i++) {
      //add to right
      right.push(numbers[i]);
      
      //move the smallest of right to left
      left.push(right.top());
      right.pop();
      
      while(cnt[i]--) {
        cout << left.top() << "\n"; //print largest of left
        
        //move largest of left to right
        right.push(left.top());
        left.pop();
      }
    }
  }
}
