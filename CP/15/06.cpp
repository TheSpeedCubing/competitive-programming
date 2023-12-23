#include <bits/stdc++.h>

using namespace std;

pair<int,int> check(string s1,string s2) {
	for(int i = 0;i<s1.length();i++){
		for(int j = 0;j<s2.length();j++){
			if(s1[i] == s2[j]) {
				return make_pair(i,j);
			}
		}
	}
	return make_pair(-1,-1);
}

string n[50];


int main() {
	string s1,s2,s3,s4;
	int flag = 0;
	while(cin >> s1 >> s2 >> s3 >> s4) {
		 if(flag++)
		   cout <<"\n";
		   
	   for(int i = 0;i<50;i++)
       n[i] = "                                                  ";
       
     pair<int,int> p1 = check(s1,s2), p2 = check(s3,s4);
     
     if(p1.first == -1 || p1.second == -1 || p2.first == -1 || p2.second == -1) {
     	  cout << "Unable to make double tens.\n";
     } else {
       int level = max(p1.second,p2.second);
       
       int i = 0;
       while(i<s1.length())
         n[level][i] = s1[i++];
         
       i+=3;
       
       int j = 0;
       while(j<s3.length())
         n[level][i+j] = s3[j++];
       
       i = 0;
       while(i<s2.length())
         n[level - p1.second + i][p1.first] = s2[i++];
       i = 0;
       while(i<s4.length())
         n[level - p2.second + i][s1.length() + 3 + p2.first] = s4[i++];
       i = 0;
       while(i < 50) {
       	  string s = n[i];
       	  while(s[s.length()-1] == ' ')
       	    s = s.substr(0,s.length()-1);
     	    if(s != "")
     	      cout << s <<"\n";
     	  i++;
     }
     }
	}
}
