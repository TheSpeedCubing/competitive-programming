#include <bits/stdc++.h>
using namespace std;

int cn[128];

vector<char> chars = {'I','V','X','L','C','D','M'};
vector<int> numbers = {1,5,10,50,100,500,1000};
vector<string> chars2 = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
vector<int> numbers2 = {1,4,5,9,10,40,50,90,100,400,500,900,1000};

int toInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (cn[s[i]] < cn[s[i + 1]]) {
            sum -= cn[s[i]];
        } else {
            sum += cn[s[i]];
        }
    }
    return sum;
}

string toStr(int n) {
    string s;
    for (int i = 12; i >= 0; i--) {
        while (n >= numbers2[i]) {
            n -= numbers2[i];
            s += chars2[i];
        }
    }
    return s;
}

int main() {
    for (int i = 0; i < 7; i++) {
        cn[chars[i]] = numbers[i];
    }

    string a, b;
    while (cin >> a) {
        if (a == "#") break;
        cin >> b;
        if (a == b) cout << "ZERO\n";
        else cout << toStr(abs(toInt(a) - toInt(b))) << "\n";
    }
}
