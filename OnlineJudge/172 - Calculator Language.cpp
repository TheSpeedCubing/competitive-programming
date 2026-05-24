#include <bits/stdc++.h>

using namespace std;

struct N {
	int i;
	char c; // A-Z or 0 (value)
};

int isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}
    
int value[128] = {};

int main() {

	string s;

	while(getline(cin, s) && s != "#") {
	    
	    // save old value
	    int old[128];
	    memcpy(old, value, sizeof(value));

        // convert to Postfix
		vector<string> result;
		stack<char> st;

		for(int i = 0; i < s.size(); i++) {
			char c = s[i];

			if(c == ' ') continue;

			if (isupper(c)) { // A-Z
				result.push_back(string(1, c));
			} else if(isdigit(c) || c == '_') { // _ and 0 ~ 9
				string n;
				if(c == '_') {
					n += '-';
					i++;
				}
				while(i < s.size() && isdigit(s[i])) {
					n += s[i++];
				}
				i--;
				result.push_back(n);
			} else if (c == '(') {
				st.push(c);
			} else if(c == ')') {
				while (!st.empty() && st.top() != '(') {
					result.push_back(string(1, st.top()));
					st.pop();
				}
				st.pop();
			} else if(isOperator(c)) { // + - * / =
				st.push(c);
			}
		}

		while(!st.empty()) {
			result.push_back(string(1, st.top()));
			st.pop();
		}
		
		// calculate
		
		stack<N> st2;
		
		for(string s : result) {
		    char c = s[0];
		    if(isupper(c)) { // A-Z
		        st2.push({0, c});
		    } else if (s.length() == 1 && isOperator(c)) { // operator
		        N b = st2.top();
		        st2.pop();
		        N a = st2.top();
		        st2.pop();

		        int av = a.c ? value[a.c] : a.i;
                int bv = b.c ? value[b.c] : b.i;
		        
		        int k = 0;
		        if(c == '+') {
		            k = av + bv;
		        } else if(c == '-') {
		            k = av - bv;
		        } else if(c == '*') {
		            k = av * bv;
		        } else if(c == '/') {
		            k = av / bv;
		        } else if(c == '=') {
		            value[a.c] = bv;
		            k = bv;
		        }
		        
		        st2.push({k, 0});
		    } else { // number
		        st2.push({stoi(s), 0});
		    }
		}
		
		int f = 0;
		for(char c = 'A'; c <= 'Z'; c++) {
		    if(old[c] == value[c]) continue;
		    
		    if(f++) cout << ", ";
		    
		    cout << c << " = " << value[c];
		}
		
		if(f == 0) cout << "No Change";
		
		cout << "\n";
	}
}
