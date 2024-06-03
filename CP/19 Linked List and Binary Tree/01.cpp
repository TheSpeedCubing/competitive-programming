#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE NODE;
struct _NODE {
    int data;
    //char id[10], name[50], addr[150], ...
    NODE *next;
};

NODE *rootList=NULL;

void traversal() 
{
	  NODE *node = rootList;
	  while (1) {
        if (node == NULL) {
        	  printf("\n"); 
        	  return;
        }
        printf("%s%d", node == rootList? "": "->", node->data);
        node = node->next;
	  }
}

void InsertOne(int val)
{
	  NODE *prev = NULL, *node = rootList;
    while (1) {
        if (node == NULL || val < node->data) {
    	      // 插入一個新的 NODE
            NODE *new_node = (NODE *)malloc(sizeof(NODE));
            new_node->data = val;
            new_node->next = node;
            if (prev == NULL) 
                rootList = new_node;
            else
                prev->next = new_node;
            return;
        }
      
        if (node->data == val) 
            return;    // 重覆，忽略它
     
        // val > node->data
        prev = node;
        node = node->next;
    }
}

void DeleteOne(int val)
{
    NODE *prev = NULL, *node = rootList;
    while (1) {
        if (node == NULL || val < node->data) 
            return;    // 找不到，忽略
    
        if (node->data == val) {
        	  // 刪除這個 NODE
            if (prev == NULL)
                rootList = node->next;
            else
                prev->next = node->next;
                
            free(node); // delete
            return; 
        }
        
        // val > node->data
        prev = node;
        node = node->next;
    }
}

void freelist()        		// 釋回記憶體
{
	  NODE *node = rootList;
	  while (node) {
        NODE *next_node = node->next;
        free(node);
        node = next_node;
	  }
}

int main()
{
    char cmd, s[10000], *token;
    while (gets(s)) {
    	
    	  cmd = s[0];
    	  if (cmd == 'p') {
            traversal();    	  	
    	  	  continue;
    	  }
    	  
    	  for (token = strtok(&s[2], " "); token; ) {
    	  	  // "5" "90" "88" "3" ...
            int val = atoi(token);
            
            if (cmd == 'i') InsertOne(val);
            else            DeleteOne(val); 
            
            token = strtok(NULL, " ");
    	  }
    }

    freelist();
    return 0;
}
