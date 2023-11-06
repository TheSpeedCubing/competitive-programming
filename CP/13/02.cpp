#include <iostream>
#include <cstring>
using namespace std;

int main() {
	
    int n[1024], o, priority;
  
    while(cin >> priority && priority){
    	 memset(n,priority,1024);
    	 int i =1 ;
        for(; i <= priority; i++){
            cin >> o;
            int index = 0;
            while(o || n[index] < i){
                o -= (n[index] > i);
                index++;
            }
            n[index] = i;
  
        }
        for(i=0; i<priority; i++)
            cout <<  n[i]<< (i==priority-1?"\n":" ");
    }
}