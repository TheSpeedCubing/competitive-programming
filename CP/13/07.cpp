#include <iostream>

using namespace std;

int array[100];     // 全域變數用於存放陣列元素
int narr=0;         // 陣列中元素個數，初值為0

// 請自行定義適當函數原型，撰寫一遞迴進行插入式排序
void insertsort(int n, int item){ 
	  if (!n || array[n - 1] <= item) {
        array[n] = item;
    } else {
        array[n] = array[n - 1];
        insertsort(n - 1, item);
    }
}

int main()
{
    int val;

    while(cin >> val){
        insertsort(narr, val);
        narr++;
    }
    for(int i=0; i<narr; i++)
        cout << array[i] << endl;

    return 0;
}