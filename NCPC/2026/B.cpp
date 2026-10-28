#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> sub(n);
    map<int,int> s2;
    long long maxDiscount = -1;

    long long k;
    for(long long i = 0;i<n;i++) {
        cin >> sub[i];
       if(sub[i] > maxDiscount) {
            s2[i] = sub[i];
            maxDiscount = max(maxDiscount, sub[i]);
        }
    }

    vector<long long> startSell(m);
    vector<long long> price(m);

    long long t, p;
    for(long long i = 0;i<m;i++) {
        cin >> t >> p;
        startSell[i] = t;
        price[i] = p;
    }

    vector<long long> expect(m);
    for(long long i = 0;i<m;i++) {
        cin >> expect[i];
    }

    map<long long,long long> r;

    long long maxW = 0;

    for(int i = 0;i<m;i++) {
        long long p = price[i];
        long long e = expect[i];
        for(auto t : s2) {
            if(t.first == n - startSell[i] + 1) {
                break;
            }
            if(e >= p - t.second) {
//                cout << t.first << " " << t.second << "\n";
                r[t.first + startSell[i]] += (p - t.second);
                maxW = max(maxW, r[t.first + startSell[i]]);
                break;
            }
        }
//            cout << "---\n";
    }
    cout << maxW << "\n";

//    vector<int> ww(m);
//
//    vector<long long> r(n);
//
//    long long maxW = 0;
//
//    for(int i = 0;i<m;i++) {
//        int p = price[i];
//        int e = expect[i];
//        if(p < e) {
//            ww[i] = 1;
//        } else {
//            int left = 0;
//            int right = n - startSell[i];
//            int nn = n;
//            while(nn--) {
//                int mid = (left + right) / 2;
////                cout << left << " " << right << " " << mid << "\n";
////                cout << e << " " << (p - sub[mid]) << "\n";
//                if(e >= p - sub[mid]) {
//                    right = mid;
//                } else {
//                    left = mid;
//                }
////                cout << left << " " << right << "\n";
//                if(left == right - 1) {
//                    if(e >= p - sub[left]) {
////                        cout << e << " " << (p - sub[right]) << "\n";
//                        r[left + startSell[i]] += (p - sub[left]);
//                        maxW = max(maxW, r[left + startSell[i]]);
//                    }
//                    if(e >= p - sub[right]) {
////                        cout << e << " " << (p - sub[right]) << "\n";
//                        r[right + startSell[i]] += (p - sub[right]);
//                        maxW = max(maxW, r[right + startSell[i]]);
//                    }
//                    break;
//                }
//            }
////            cout << "---\n";
//        }
//    }
//
//    cout << maxW << "\n";

//    vector<int> ww(m);
//
//    vector<long long> r(n);
//
//    long long maxW = 0;
//
//    for(int i = 0;i<m;i++) {
//        int p = price[i];
//        int e = expect[i];
//        for(int j = 0;j< n - startSell[i] + 1;j++) {
//            if(e >= p - sub[j]) {
//                r[j + startSell[i]] += (p - sub[j]);
//                maxW = max(maxW, r[j + startSell[i]]);
//                break;
//            }
//        }
//    }
//
//    cout << maxW << "\n";

//    vector<bool> bought(m, false);
//
//    long long bCnt = 0;
//    long long mm = 0;
//    long long week = 0;
//    for(long long i = 0;i<n;i++) {
//        long long sum = 0;
//        long long notBoughtSum = 0;
//        for(long long j = 0;j<m;j++) {
//            long long w = i + 1;
//            int r = 0;
//            if(w >= startSell[j]) {
//                r = price[j] - sub[w - startSell[j]];
//            } else {
//                r = price[j];
//            }
//            if(!bought[j]) {
//                if(r <= expect[j]) {
//                    bought[j] = true;
//                    bCnt++;
//                    sum += r;
//                } else {
//                    notBoughtSum += r;
//                }
//            }
//        }
//        mm = max(sum, mm);
//        if(bCnt == m) {
//            break;
//        }
//        if(notBoughtSum <= mm) {
//            break;
//        }
//    }
//    cout << mm << "\n";
}