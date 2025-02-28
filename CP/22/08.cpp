#include <bits/stdc++.h>

using namespace std;

string s1, s2;

int m[128];
	
struct Tree {
	char value;
	Tree *left, *right;
	Tree(char value,Tree* left,Tree* right) : value(value),left(left),right(right) {
	}
};

Tree* f(int i1,int i2,int i3,int i4) {
    int i = m[s1[i1]];
    
    return (i1 > i2 || i3 > i4) ? NULL :
           new Tree(
    	s1[i1],
      f(i1 + 1         , i1 + i - i3, i3   , i - 1),
      f(i1 + 1 + i - i3, i2         , i + 1, i4)
    );
}

void v(Tree* root) {
    if (root == NULL) {
        return;
    }
    v(root->left);
    v(root->right);
    cout << root->value;
}

int main() {
	while(cin >> s1 >> s2) {
		 int i = 0;
	   for(char c : s2) {
		   m[c] = i++;
	   }
		 v(f(0,i-1,0,i-1));
		 cout <<"\n";
	}
}

