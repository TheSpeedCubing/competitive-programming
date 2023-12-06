#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1;t<=T;t++) {
		 int size;
		 cin >> size;
		 
		 vector<vector<int>> arr(size,vector<int>(size,0));
		 
		 for(int i = 0;i<size;i++){
		 	 for(int j = 0;j<size;j++){
		 		 char in;
		 		 cin >> in;
		 		 arr[i][j] = in - 48;
		 	 }
		 	 cin.ignore();
		 }
		 
		 int cmd;
		 cin >> cmd;
		 while(cmd--){
		 	string prefix;
		 	cin >> prefix;
		 	if(prefix=="transpose"){
		 	
		 for(int i = 0;i<size-1;i++){
		 	 for(int j = i+1;j<size;j++){
		 	 	swap(arr[i][j],arr[j][i]);
		 	 }
		 }	
		 	} else
		 	if(prefix=="inc" || prefix=="dec"){
		 	
		 for(int i = 0;i<size;i++){
		 	 for(int j = 0;j<size;j++){
		 	 	 int x=arr[i][j];
		 	 	 if(prefix=="inc")
		 	 	   arr[i][j]=(x==9?0:(x+1));
		 	 	 else arr[i][j]=(x==0?9:(x-1));
		 	 }
		 }
		 	} else{
		 	int x,y;
		 		cin>>x>>y;
		 		x--;
		 		y--;
		 		for(int i = 0;i<size;i++){
		 			if(prefix=="row")
		 			  swap(arr[x][i],arr[y][i]);
		 			else swap(arr[i][x],arr[i][y]);
		 		}
		 	}
		 }
		 
		 cout<<"Case #"<<t<<"\n";
		 for(int i = 0;i<size;i++){
		 	 for(int j = 0;j<size;j++){
		 	 	 cout<<arr[i][j];
		 	 }
		 	 cout<<"\n";
		 }
		 cout<<"\n";
	}
}
