#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// 以下結構內部須有4個欄位a, b, c, d
// 可以存放整數 0~3
struct {
	unsigned char a:2;
	unsigned char c:2;
	unsigned char b:2;
	unsigned char d:2;
} bigarray[1000000000];
// 你的工作式完成以上結構定義


int main()
{
    int seed;

    cin >> seed;

    srand(seed);

    int index;
    while(cin >>index){
        if(index<0) break;
        int a=rand()%4, b=rand()%4, c=rand()%4, d=rand()%4;
        cout << (int)(bigarray[index].a = a) << " "
             << (int)(bigarray[index].b = b) << " "
             << (int)(bigarray[index].c = c) << " "
             << (int)(bigarray[index].d = d) << endl;
        cout << (bigarray[index].a==a) << " "
             << (bigarray[index].b==b) << " "
             << (bigarray[index].c==c) << " "
             << (bigarray[index].d==d) << endl;
    }
    return 0;
}
