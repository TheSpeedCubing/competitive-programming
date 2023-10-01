#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello CodingPass!";
    for(int i = 1;i<=17;i++)
       cout << str.substr(0,i)<< "\n";
}