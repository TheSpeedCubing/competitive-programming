#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 1024

void inToPostfix(char*, char*);
int getPriority(char);
int eval(char*); 
int cal(char, int, int); 

int main(void){
 char infix[MAX] = {'\0'};
 
 while(scanf("%[^\n]", infix) != EOF){
  getchar();
  printf("%d\n", eval(infix));
 }
 
 return 0;
}

void inToPostfix(char *infix, char *postfix){
 char stack[MAX] = {'\0'};
 int i, j, top = -1;
 for(i=0,j=0; infix[i]!='\0'; i++){
  if(infix[i] == ' '){
   continue;
  }
  if(infix[i] == '('){
   stack[++top] = infix[i]; //push
  }else if(infix[i] == '+'||infix[i] == '-'||infix[i] == '*'||infix[i] == '/'||infix[i] == '%'){
   while(top >= 0 && getPriority(stack[top]) >= getPriority(infix[i])){
    postfix[j++] = stack[top--]; //pop
   }
   stack[++top] = infix[i]; //push
  }else if(infix[i] == ')'){
   while(top >=0 && stack[top] != '('){
    postfix[j++] = stack[top--]; //pop至'(' 
   }
   top--; 
  }else if(isdigit(infix[i])){
   while(isdigit(infix[i])){
    postfix[j++] = infix[i++];
   }
   postfix[j++] = ' ';
   i--;
  }
 }
 while(top >= 0){
  postfix[j++] = stack[top--];
 }
 postfix[j] = '\0';
}

int getPriority(char op){
    if(op == '+'||op == '-'){
        return 1;
    }else if(op == '*'||op == '/'||op == '%'){
        return 2;
    }else{
        return 0;
    }
}

int eval(char *infix){
 char postfix[MAX] = {'\0'};
 char temp[20] = {'\0'};
 int stack[MAX] = {0.0};
 
 inToPostfix(infix, postfix);
 
 int top = -1, i;
 for(i=0; postfix[i]!='\0'; i++){
  if(postfix[i] == '+'||postfix[i] == '-'||postfix[i] == '*'||postfix[i] == '/'||postfix[i] == '%'){
   int p2 = stack[top--];
   int p1 = stack[top--];
   stack[++top] = cal(postfix[i], p1, p2);
  }else if(isdigit(postfix[i])){
   int j = 0;
   while(isdigit(postfix[i])){
    temp[j++] = postfix[i++];
   }
   temp[j] = '\0';
   stack[++top] = atof(temp);
   i--;
  }
 }
 return stack[top];
}

int cal(char op, int p1, int p2){
 if(op == '+'){
  return p1 + p2;
 }else if(op == '-'){
  return p1 - p2;
 }else if(op == '*'){
  return p1 * p2;
 }else if(op == '/'){
  return p1 / p2;
 }else if(op == '%'){
  return p1 % p2;
 }
}
