#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long male[32768] = {0};
	long long female[32768] = {1};
	int N;
	int i = 0;
	while(cin >> N && N != -1) {
			while(i < N) {
				female[i+1] = male[i] + 1;
				male[i+1] = male[i] + female[i];
				i++;
			}
			cout << male[N] <<" "<<(male[N]+female[N])<<"\n";
	}
}
