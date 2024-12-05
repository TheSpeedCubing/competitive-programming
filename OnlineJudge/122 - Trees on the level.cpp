#include <bits/stdc++.h>

using namespace std;


int getNodeCount(int level) {
  return (int) pow(2, level);
}

int getTotalNodeCount(int level) {
  int t = 0;
  for (int i = 0; i <= level; i++) {
    t += (int) pow(2, i);
  }
  return t;
}

int main() {

  while (1) {
	  map<int,int> tree; //key: index, value: number
	  set<int> visited;
    vector<int> numbers;
	  vector<string> pos;
    
    string s, s2;
    while (1) {
      if (!(cin >> s)) {
        exit(0);
      }
      if (s == "()") {
        break;
      }
      stringstream ss(s);
      char c;
      ss >> c;
      int n;
      ss >> n;
      ss >> c;
      ss >> s2;
      numbers.push_back(n);
      pos.push_back(s2.substr(0, s2.length() - 1));
    }

    bool f = true;
    for (int i = 0;i<numbers.size();i++) {
      string str = pos[i];
      int level = str.length();

      int index = 0;
      int lvl = 0;
      for (char c : str) {
        if (c == 'R') {
          index += getNodeCount(level - lvl - 1);
        }
        lvl++;
      }
	  
      index += getTotalNodeCount(level - 1);
      if (tree[index] != 0) {
        f = false;
        break;
      }
      tree[index] = numbers[i];
    }

	vector<int> result;
    if (f) {
      int head = tree[0];
      if (head == 0) {
        f = false;
      } else {
        queue<pair<int,int>> q; // index, level
        q.push({0,0});
        while (!q.empty()) {
          pair<int,int> p = q.front();
          q.pop();
          if (tree[p.first] == 0) {
            continue;
          }

          int tg = getTotalNodeCount(p.second + 1) - 2 * (getTotalNodeCount(p.second) - p.first);
          result.push_back(tree[p.first]);
          visited.insert(tree[p.first]);
          q.push({tg, p.second + 1});
          q.push({tg + 1, p.second + 1});
        }
      }
    }

    if (f) {
      for (int i : numbers) {
        if (visited.count(i) == 0) {
          f = 0;
          break;
        }
      }
    }
    
    if (!f) {
      cout << "not complete\n";
    } else {
	  int f = 0;
    for (int i : result) {
	    if (f++) cout <<" ";
        cout << i;
      }
      cout << "\n";
    }
  }
}
