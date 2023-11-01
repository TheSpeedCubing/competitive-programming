#include <iostream>
using namespace std;

int main()
{
	string s;
	while(cin >> s){
		int score = 0,lastS=0;
		for(char c : s){
			if(c == 'X')
			   lastS = 0;
		  else {
		  	lastS++;
		  	score+=lastS;
		  }
		}
		cout << score <<"\n";
	}
}
