#include <iostream>

using namespace std;

int main()
{
	string s;
	while(cin >> s) {
	   	bool pr = 0;
	    for(int i = 2;i<=11;i++){
	       int l = 0;
	   	   for(char c : s) {
	   		   int d = c - '0';
	   		 	 l = (l % i ? l * 10 + d : d) % i;
	   		}
	   		if(!l) {
	   		   cout << (pr ? ",":"") << i;
	   		   pr = 1;
	   		}
	   	}
	   	cout << (pr ? "\n" :"-\n");
	}
}


// #include <iostream>
// 
// using namespace std;
// 
// int main()
// {
//     string s;
//     while (cin >> s) {
// 
//         int len = s.length(),
//             digitSum = 0,
//             crossSum = 0,
//             verify7 = 0,
//             last3 = 0,
//             last2 = 0,
//             last1 = 0,
//             what_the_hell_is_this[] = {1, 3, 2, 6, 4, 5},
//             i = 0;
// 
//         for (; i < len; i++) {
//             int thisDigit = s[len - i - 1] - 48;
//             if (i == 0)
//                 last3 = last2 = last1 = thisDigit;
//             if (i == 1)
//                 last3 = (last2 += thisDigit * 10);
//             if (i == 2)
//                 last3 += thisDigit * 100;
// 
//             digitSum += thisDigit;
//             crossSum += i % 2 ? -thisDigit : thisDigit;
//             verify7 += thisDigit * what_the_hell_is_this[i % 6];
//         }
// 
//         bool NY = 1,
//             result[] = {
//                 last1 % 2,
//                 digitSum % 3,
//                 last2 % 4,
//                 last1 % 5,
//                 result[0] || result[1],
//                 verify7 % 7,
//                 last3 % 8,
//                 digitSum % 9,
//                 last1,
//                 crossSum % 11
//             };
// 
//         for (len = 0; len < 10; len++) {
//             if (!result[len]) {
//                 if (NY)
//                     NY = 0;
//                 else
//                     cout << ",";
// 
//                 cout << (len + 2);
//             }
//         }
//         cout << (NY ? "-\n" : "\n");
//     }
// }
