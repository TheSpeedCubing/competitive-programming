#include <iostream>
#include <string>

using namespace std;

string s;
int search(string data){
	  int c = 0;
		for(char ch : s) {
			c+= (data[c] == tolower(ch));
			if(!data[c])
			  return 0;
		}
		return 1;
}

int main()
{
	while(getline(cin,s)){
		 cout << (search("cloud") || search("sun") ? "Fail\n" : "Success\n");
	}
}
