// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>
#include <iterator>

using namespace std;

int arr[1024];
int arrSize = 0;

void printTheArray() {
    for (int i = 0; i < arrSize; i++) {
        cout << (i == 0 ? "" : " ") << arr[i];
    }
    cout << "\n";
}

void insert(int v) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > v) {
            arrSize++;
            memmove(arr + i + 1, arr + i, (arrSize - i) * sizeof(int));
            arr[i] = v;
            return;
        }
    }
    arr[arrSize] = v;
    arrSize++;
}

void del(int v) {
    int s = 0;
    int cnt = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] != v) {
            arr[s++] = arr[i];
        }
        else cnt++;
    }
    arrSize -= cnt;
}


char c;
int i;

int main() {
    while (true) {
        cout << "Input or Delete? ";
        cin >> c;
        cout << "Input an integer? ";
        cin >> i;
        if (tolower(c) == 'i') {
            insert(i);
        }
        else if (tolower(c) == 'd') {
            del(i);
        }

        printTheArray();
    }
}