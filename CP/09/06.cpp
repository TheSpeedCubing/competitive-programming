#include <iostream>
#include <string>

using namespace std;

int n[1024], target, flag, head, dt;
string s, s2;
void add() {
    n[target] += flag ? 0 : (s2[6] == '+' ? 1 : -1);
}

int main() {
  int c, i = 0;
  cin >> s;
  while (s[i]) {
    cin >> c;
    n[s[i]] = c;
    i++;
  }
  cin >> c;
  getline(cin, s2);
  while (getline(cin, s2)) {
    head = s2[0], flag = isalpha(s2[5]), target = s2[flag ? 5 : 7];
    add();
    dt = n[target];
    switch(s2[2]){
    	case '+':
        n[head] += dt; break;
    	case '-':
        n[head] -= dt; break;
    	case '*':
        n[head] *= dt; break;
      case '/':
        if(dt)
          n[head] /=dt;
         break;
      case '%':
        if(dt)
           n[head]%=dt;
         break;
    }
    flag = !flag;
    add();
  }
  for(i=0;s[i];i++)
    cout << n[s[i]] << (s[i + 1] ? " " : "\n");
}