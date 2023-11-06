#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	int n,flag=1;
	while(cin >> n){
		if(flag)
      flag =0;
    else cout <<"\n";
    
		string s = " *\n * *\n   *", mid=" *";
		
		for(int i = 2;i<=n;i++){
			int t = pow(2,i);
		    string s2 = "", s3;
		    istringstream ss(s);
		    
		    while(getline(ss,s3,'\n')) {
		        int r = t;
		        while(r--)
		            s2+=" ";
		        s2+=s3+"\n";
		    }
		    s+="\n";
		    
		    while(t--)
		        s+=mid;

		    s+="\n"+s2.substr(0,s2.length()-1);
		}
		cout << s<<"\n";
	}
}
