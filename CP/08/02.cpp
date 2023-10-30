#include <iostream>
using namespace std;

int main()
{
    int t, cnt, flag=1,i,pos[1024];
    char buffer[100][1024];
    cin >> t;
    while(t--){
        if(flag) 
          flag = 0;
        else printf("\n");
        cin >>cnt;
        for(i=0;i<cnt;i++)
          cin >> pos[i];
        for(i=0;i<cnt;i++)
          cin >> buffer[i];
        for(i=0;i<cnt;i++)
          cout <<buffer[pos[i]]<<"\n";
    }
}