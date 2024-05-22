#include <bits/stdc++.h>

using namespace std;

vector<string> resultSet;
void f(int n, int factor, string s) {
    
    while (factor <= sqrt(n)) {
        if (n % factor == 0) {
              //append the factor to the string
            f(n/factor, factor, s + " " + to_string(factor));
        }
        factor++;
    }
    
    if(s != "") //ignore if the n equals to the original N
      resultSet.push_back(s.substr(1) + " " + to_string(n)); //remove the first space
}

int main() {
    int N;

    while (cin >> N && N) {
          f(N,2, "");
          cout << resultSet.size() <<"\n";
          for(string s : resultSet) {
               cout << s <<"\n";
          }
          resultSet.clear();
    }
}
