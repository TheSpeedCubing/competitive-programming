#include <bits/stdc++.h>

using namespace std;

map < string, vector < pair < string, string >>> mongo;
vector < string > title;

int state;
int main() {
  string s, name;

  while (getline(cin, s)) {
    if (s == "^^^")
      break;
    stringstream ss(s);
    
    int i = 0;
    while (getline(ss, s, ',')) {
      if (state) {
        if (i++) {
          mongo[title[i - 1]].push_back({s,name});
        } else {
          name = s;
        }
      } else {
        title.push_back(s.substr(0, s.length() - 3));
      }
    }
    
    state = 1;
  }
  for (string s: title) {
    sort(mongo[s].begin(), mongo[s].end(), [](pair < string, string > a, pair < string, string > b) {
      return a.first == b.first ?
                a.second < b.second :
             (isdigit(b.first[0]) ?
          stod(a.first) > stod(b.first) :
              a.first < b.first);
    });
  }

  while (getline(cin, s, ',')) {
    cin >> state;
    cin.ignore();
    cout << mongo[s][state - 1].second << "\n";
  }
}