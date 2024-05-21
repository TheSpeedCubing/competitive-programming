#include <bits/stdc++.h>

using namespace std;
int main() {
    int T;
    cin >> T;

    unsigned long long N;

    string s;
    while (T--) {
        cin >> s >> N;
        N++;

        int length = s.length();

        //sort string
        sort(s.begin(), s.end());

        //use vector string
        vector < char > str;
        for (char c: s) {
            str.push_back(c);
        }

        unsigned long long subPossibility = 1;

        for (int i = 1; i < length; i++) {
            subPossibility *= i;
        }

        length -= 1;
        while (true) {
            int index = (int)((N - 1) / subPossibility);

            cout << str[index];

            str.erase(str.begin() + index);

            if (length == 0) {
                break;
            }

            N -= index * subPossibility;
            subPossibility /= length;
            length--;
        }
        cout << "\n";
    }
}
