#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void InsertNode(NODE **lst, int val)
{
	  NODE *node = *lst;
    if (node == NULL || val < node->data) {
    	  // 插入一個新的 NODE
        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        new_node->data = val;
        new_node->next = node;
        *lst = new_node;
        return;
    }
    
    if (node->data == val) 
        return;    // 重覆，忽略它
    
    // node->data > val，看下一個 next
    InsertNode(&(node->next), val);
}

void RemoveNode(NODE **lst, int val)
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
    RemoveNode(&(node->next), val);
}

void freelist(NODE *node)        		// 釋回記憶體
{
    if (node == NULL) return;
    
    NODE *next_node = node->next;
    free(node);
    
    freelist(next_node);
}

int main()
{
    char cmd, s[1024], *token;

    while (gets(s)) {
       
        if ((cmd = s[0]) == 'p')
        	  traversal(rootList);

        else 
        	  for (token = strtok(&s[2], " "); token; ) {
        	  	  // "5" "90" "88" "3" ...
                int val = atoi(token);
            
                if (cmd == 'i') 
                    InsertNode(&rootList, val);
                else // if (cmd == 'd')
                    RemoveNode(&rootList, val);
                
                token = strtok(NULL, " ");
      	    }
    }
    freelist(rootList);
    return 0;
}
