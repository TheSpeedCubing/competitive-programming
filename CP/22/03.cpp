#include <bits/stdc++.h>

using namespace std;

int N, flag, in;

int main() {
  while (cin >> N && N) {
    if(flag++) {
    	 cout << endl;
    }
    while (true) {
      vector<int> before, after;
      for (int i = 0; i < N; i++) {
      	cin >> in;
      	if (!in) {
        	goto outside;
        }
        after.push_back(in);
        before.push_back(i+1);
      }
        
      int ia = 0;
      int ib = 0;
      bool possible = true;
      while(true) {
        bool found = false;
        while(after[ia] == before[ib]) {
      	  found = true;
      	  before.erase(ib+before.begin());
      	  ia++;
        	if(ib)
        	 	ib--;
          if(ib == 0 && ia == N) {
          	possible = true;
        	  goto finish;
          }
        }
        	 if(ib == N) {
        	 	 possible = ia==N-1;
        	   break;
        	 }
        ib++;
      }
      finish:
        cout << (possible ? "Yes\n" : "No\n");
    }
    outside:{}
  }
  cout << flush;
}
