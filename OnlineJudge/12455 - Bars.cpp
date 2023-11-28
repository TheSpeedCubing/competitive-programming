#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		
		int T2;
		cin >> T2;
		
		int F[N+1] = {1};
		
		int L[T2];
		
	  for(int i = 0;i<T2;i++)
	    cin >> L[i];
	    
	   for (int i = 0;i<T2;i++)
	   	 for (int j = N;j>=L[i];j--)
	   	   if (F[j-L[i]])
	   	     F[j] = 1;
	   	     
	  cout <<(F[N] ?"YES\n" :"NO\n");
	}
}
