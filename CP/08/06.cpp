#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while(getline(cin,s)){
		int score = 0,lastS=0,i=0;
		for(;i<s.length();i++){
			if(s[i] == 'X')
			   lastS = 0;
		  else {
		  	lastS++;
		  	score+=lastS;
		  }
		}
		cout << score <<"\n";
	}
}