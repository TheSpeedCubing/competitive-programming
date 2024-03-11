#include <bits/stdc++.h>

using namespace std;

int t, n, m, o, a, b, f;

int main() {
  cin >> t;
  while (t--) {
    if(f++)
        cout << "\n";
    map < string, map < int, map < int, int >>> db;
    map < string, int > in;
    
    char es;
    cin >> n;
    double d[11];
    
    int i = 0;
    while(i<= n) {
      cin >> d[i++];
      cin.ignore();
    }

    while(d[n]--) {
      string userID, s2;
      getline(cin, userID, ',');
      getline(cin, s2, ',');
      cin >> o;

      while(o--) {
        cin >> es >> a >> es >> b;
        db[userID][s2 == "Y" ? in [userID] : -1][a] += b;
      }
      cin.ignore();
       
      in [userID]+= (s2 == "Y");
    }

    for (const auto & p1: db) {
      for (const auto & p2: p1.second) {
        cout << p1.first <<" ";
        stringstream ss;
        int m2 = 0;
        for (const auto & p3: p2.second) {
          ss << " "<< p3.first<< " "  << p3.second;
          m2 += d[p3.first-1] * 10 * p3.second;
        }
        cout << m2/10 <<ss.str()<<"\n";
      }
    }
  }
}