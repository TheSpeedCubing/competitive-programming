#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int flag = 1;
    while(getline(cin,s)){
    	if(flag)
    	  flag=0;
    	else
    	   cout <<"\n";
    	   
    	 char n[1024][1024] = {0};
    	 int max[1024] = {0} , row = 0,column=0,maxcol=0,f=1,i=0;
    	 
    	 
    	 for(;s[i];i++){
    	 	  if(s[i]==' ') {
    	 	  	if(s[i+1] !=' ' && !f) {
    	 	  	  row++;
    	 	  	  column=0;
    	 	    }
    	 	  } else {
    	 	  	 f=0;
    	 	  	 n[row][column] = s[i];
    	 	  	 max[column] = row > max[column] ? row : max[column];
    	 	  	 column++;
    	 	  	 maxcol = column > maxcol ? column : maxcol;
    	 	  }
    	 }
    	 for(i = 0;i < maxcol;i++){
    	 	  for(int j = 0;j<=max[i];j++)
    	 	  	  cout << (n[j][i] == NULL ? ' ' : n[j][i]);
    	 	  cout <<"\n";
    	 }
    }
}
