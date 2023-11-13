#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	 int T,id;
	 while(cin >> T) {
	   vector<int> slaves;
	 	 while(T--){
	   cin >> id;
	 	 slaves.push_back(id);
	 	}
	   sort(slaves.begin(),slaves.end(),[](int a,int b){
	 	   return a % 2 ? (b % 2 && a > b) : (b % 2 || a > b );
	   });
	   for(int i = 0;i<slaves.size();i++){
	   	 cout << slaves[i] << (i == slaves.size() -1 ? "\n":" ");
	   }
	}
}
