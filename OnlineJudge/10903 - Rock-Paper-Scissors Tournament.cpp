#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int n,k;
	int flag = 1;
	while(cin >> n && n != 0) {
		if(flag)
		  flag = 0;
		else cout <<"\n";
		
		cin >> k;
		k = k * n * (n-1) /2;
		int win[n+1] = {0};
		int lose[n+1] = {0};
		while(k--) {
			int a,b;
			string s1,s2;
			cin >> a >> s1 >> b >> s2;
			if(s1 == "scissors") {
				 if(s2 == "rock"){
				 	 win[b]++;
				 	 lose[a]++;
				 }
				 if(s2 == "paper") {
				 	 win[a]++;
				 	 lose[b]++;
				 }
			}
			if(s1 == "rock") {
				 if(s2 == "scissors"){
				 	 win[a]++;
				 	 lose[b]++;
				 }
				 if(s2 == "paper") {
				 	 win[b]++;
				 	 lose[a]++;
				 }
			}
			if(s1 == "paper") {
				 if(s2 == "scissors"){
				 	 win[b]++;
				 	 lose[a]++;
				 }
				 if(s2 == "rock") {
				 	 win[a]++;
				 	 lose[b]++;
				 }
			}
		}
		
		for(int i = 1;i<=n;i++){
			if(win[i] + lose[i] == 0){
				cout <<"-\n";
			} else 
			  cout <<fixed << setprecision(3)<< round((double) win[i] / (win[i] + lose[i]) * 1000)/1000<<"\n";
		}
	}
}
