#include <iostream>
#include <cstring>

using namespace std;

struct NODE {
	  int val;
    NODE *left;
    NODE *right;
};

NODE *make_tree() {
	  int val;
	  cin >> val;
	  if (val == 0) return NULL;
	  
	  NODE *n = new NODE;
	  n->val = val;
	  n->left  = make_tree();
	  n->right = make_tree();

	  return(n);
}

int right_view[2000], max_depth;
void prt_tree(NODE *n, int k) {
	  if (n == NULL) return;
	  
	  prt_tree(n->left, k+1);
	  
	  right_view[k] = n->val;
	  
	  max_depth=max(max_depth,k);
	  prt_tree(n->right, k+1);
}

void free_tree(NODE *n) {
	  if (n == NULL) return;
	  
	  free_tree(n->left);
	  free_tree(n->right);
	  delete n;
}

int main()
{
    int t; cin >> t;
    while (t--) {
    	  
    	  NODE *root = make_tree();
    	  
    	  max_depth = 0;
    	  memset(right_view, 0, sizeof(right_view));
    	  
        prt_tree(root, 0);
        
        for (int i=0; i<=max_depth; i++)
            cout << right_view[i] << (i==max_depth ? "\n": " ");
    
        free_tree(root);
    }
    return 0;
}
