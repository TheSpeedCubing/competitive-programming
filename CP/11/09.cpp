#include <bits/stdc++.h>

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
      if(type[ABList[query]] == "None") {
         cout <<"None\n";
	 	  	continue;
       }
	 	  
	 	  auto it = lower_bound(arr.begin(), arr.end(), query);
	 	  if(it == arr.end()) {
         cout <<"None\n";
	 	  	continue;
	 	  } 
         cout << (distance(arr.begin(),it)+1) <<" "<< type[ABList[query]]<<"\n";
	 	  
   }
}
