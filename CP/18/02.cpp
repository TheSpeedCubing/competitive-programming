#include <bits/stdc++.h>

using namespace std;

string placeholder(string s, string tg,bool f) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '%' && (f || i == 0 || s[i - 1] != '\\')) {
      s = s.substr(0, i) + tg + s.substr(i + 1);
      if(f)
        i++;
      else
        break;
    }
  }
  return s;
}

int main()
{
	string s;
	int flag = 0;
	string error;
	while(1) {
		if(error.length()) {
		  s = error.substr(0,error.length()-1);
		  error = "";
		} else {
			if(getline(cin,s))
			  s = s.substr(1,s.length()-2);
			else exit(0);
		}
		
		if(flag++)
		  cout <<"^^^\n";
		
		char c;
		while(cin.get(c) && c !='\n') {
			if(c == 'd') {
				int t, in, sum = 0;
				cin >> t;
				while(t--) {
				  cin >> in;
				  sum+=in;
				}
		    s = placeholder(s,to_string(sum),false);
			}
			if(c == 'r') {
				double t, in, sum = 0;
				cin >> t;
				while(t--) {
				  cin >> in;
				  sum+=in;
				}
        stringstream stream;
        stream << fixed << setprecision(2) << sum;
		    s = placeholder(s,stream.str(),false);
			}
			if(c == 's') {
				string s2;
				getline(cin,s2);
		    s = placeholder(s,placeholder(s2.substr(2,s2.length()-3),"\\%",true),false);
			} else {
				getline(cin,error);
				if (error.length())
				   break;
			}
		}
		for(int i = 0;i<s.length();i++){
		  if(s[i] == '\\') {
		    char next = s[i + 1];
        if (next == '%' || next == '\"' || next == '\\')
          s = s.substr(0, i) + s.substr(i + 1);
        else if (next == 'n') {
          s = s.substr(0, i) + '\n' + s.substr(i + 2);
        }
		  }
		}
		cout << s;
		if(s[s.length()-1] != '\n')
		  cout <<"\n";
		}
}

