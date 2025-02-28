#include <bits/stdc++.h>
using namespace std;

deque<int>* arr[25];
map<int,int> loc;

deque<int>* get(int i) {
  return arr[loc[i]];
}

int indexOf(int i) {
	return distance(get(i)->begin(), find(get(i)->begin(),get(i)->end(),i));
}

void clearBehind(int i) {
		int index = indexOf(i);
		while(get(i)->size() != index+1) {
		 	 int v = get(i)->back();
		 	 get(i)->pop_back();
	      arr[v]->push_back(v);
	      loc[v] = v;
		}
}
int main() {
	int n;
	cin >> n;
	
	int n2 = n;
	while(n2--) {
		 arr[n2] = new deque<int>();
		 arr[n2]->push_back(n2);
		 loc[n2] = n2;
	}
	
	string s, s2;
	int a, b;
	while(cin >> s && s != "quit") {
		 cin >> a >> s2 >> b;
		 if(a == b || loc[a] == loc[b])
		   continue;
		 if(s2 == "over") {
		 	  b = get(b)->back();
		 }
		 clearBehind(b);
		 if(s == "pile") {
		 	  int index = indexOf(a);
		 	  int l = loc[a];
		 	  while(arr[l]->size() != index) {
		 	  	 int v = get(a)->back();
		 	     get(a)->pop_back();
		 	  	 get(b)->insert(get(b)->begin()+indexOf(b)+1,v);
		 	  	 loc[v] = loc[b];
		 	  }
		 }
		 if(s == "move") {
		 	  clearBehind(a);
		 	  get(a)->pop_back();
		 	  get(b)->push_back(a);
		 	  loc[a] = loc[b];
		 }
	}
	
	for(int i = 0;i<n;i++) {
		 cout << i <<":";
		 for(int j : *arr[i]) {
		 	 cout <<" "<< j ;
		 }
		 cout <<"\n";
	}
}

