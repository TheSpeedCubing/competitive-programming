/*
  使用stack
  ( [ push
  ) ] 看 top 是不是對應，是: pop, 否: No
  如果最後stack內有東西，也是No
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; 
    cin >> t;
    cin.ignore();
    
    string s;
    while (t--) {
        getline(cin, s);
        
        stack<char> st;
        
        bool f = true;
        for (char c : s) {
            if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                 } else f = false;
            } else if (c == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else f = false;
            } else {
                st.push(c);
                if(!f) {
                    break;
                }
            }
        }
        cout << (f && st.empty() ? "Yes\n" : "No\n");
    }
}
