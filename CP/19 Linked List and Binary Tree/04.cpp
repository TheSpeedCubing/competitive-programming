#include <iostream>
using namespace std;

typedef struct _NODE NODE;
struct _NODE {
    int data;
    NODE *next;
};

NODE *rootList=NULL;

void traversal(NODE *node)
{
    if (node == NULL) printf("\n");
    else {
        printf("%s%d", node==rootList ? "":"->", node->data);
        traversal(node->next);
    }
}

void DeleteNode(NODE **lst, int val)
{
	  NODE *node = *lst;
    if (node == NULL || val < node->data) 
        return;    // 找不到，忽略
    
    if (node->data == val) {
    	  // 刪除這個 NODE
        *lst = node->next;
        free(node); // delete
        return;
    }
    
    // node->data > val, 看下一個 next
    DeleteNode(&(node->next), val);
}
void InsertNode(NODE **lst, int val)
{
	  NODE *node = *lst;
    if (node == NULL || val < node->data) {
    	  // 插入一個新的 NODE
        NODE *new_node = new NODE;  //(NODE *)malloc(sizeof(NODE));
        new_node->data = val;
        new_node->next = node;
        *lst = new_node;
        return;
    }
    
    if (node->data == val) return;    // 重覆，忽略它
    
    // node->data > val，看下一個 next
    InsertNode(&(node->next), val);
}

void freelist(NODE *node)        		// 釋回記憶體
{
    if (node == NULL) return;
    
    NODE *next_node = node->next;
    delete node; //free(node);
    
    freelist(next_node);
}

int main()
{
    char cmd, s[2], *p;
    while (scanf("%s", s) == 1) {

        if ((cmd = s[0]) == 'p')
        	  traversal(rootList);

        else {
            int val;
            while (scanf("%d", &val) == 1) {
            	  if (cmd == 'i') 
                    InsertNode(&rootList, val);
                else // if (cmd == 'd')
                    DeleteNode(&rootList, val);
            }
        }
    }
    freelist(rootList);
    return 0;
}
