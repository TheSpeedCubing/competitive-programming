#include <bits/stdc++.h>

using namespace std;

int prior(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    
    string s;
    
    int f = 0;
    while(t--) {
        if(f++) cout << "\n";
        
        stack<char> st;
        
        string result;
        
        while(getline(cin, s) && s != "") {
            char c = s[0];
            
            if(isdigit(c)) {
                result += c;
            } else if (c == '(') {
                st.push(c);
            } else if(c == ')') {
                while (!st.empty() && st.top() != '(') { // top = + - * /
                    result += st.top();
                    st.pop();
                }
                st.pop();
            } else { // c = + - * /
                while (!st.empty() && prior(st.top()) >= prior(c)) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        cout << result << "\n";
    }
}
