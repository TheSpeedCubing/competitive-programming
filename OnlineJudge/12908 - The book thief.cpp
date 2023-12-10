#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long  N;
	while(cin >>N && N) {
			long long  f = (int) floor((sqrt(1+8*N) - 1)/2);
		
		if(f * (f+1) / 2 <= N)
			f++;
		
		cout<< (f * (f+1) / 2 - N) <<" "<<f<<"\n";
	}
}
