#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char ABList[10000000];
string type[] = {"None","A","B","AB"};
int m,n,id,T, query;
vector<int> arr;

int main() {
	 cin >> m >>n;
	 while(m--) {
	 	 cin >> id;
	 	 if(!ABList[id])
	 	   arr.push_back(id);
	 	 ABList[id]++;
	 }
	 while(n--) {
	 	 cin >> id;
	 	 if(!ABList[id])
	 	   arr.push_back(id);
	 	 ABList[id] += 2;
	 }
	 sort(arr.begin(),arr.end());
	 cin >> T;
	 while(T--) {
	 	  cin >> query;
	 	  int index = find(arr.begin(), arr.end(), query) - arr.begin() + 1;
	 	  if(index > arr.size()){
	 	  	cout <<"None\n";
	 	  } else 
	 	    cout << index <<" "<<type[ABList[query]]<<"\n";
	 }
}
