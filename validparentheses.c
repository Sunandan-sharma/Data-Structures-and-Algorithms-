#include<stdio.h>
#define MAX 100
int stack[MAX],top=-1;
int isEmpty(){
    return (top == -1) ? 1 : 0;
}
int isFull(){
    return (top == MAX-1) ? 1 : 0;
}
void push(char val){
    if (!isFull()) {
        top++;
        stack[top] = val;
    }
}
void pop(){
        top--;
}
int valid_parenthesis(char *arr){
    for (int i = 0; arr[i]!='\0'; i++){
        if(arr[i]=='(' || arr[i]=='{' || arr[i]=='['){
            push(arr[i]);
        }else if(arr[i]==')'){
            if(stack[top]=='('){
                pop();
            }else{
                return 0;
            }
        }else if(arr[i]=='}'){
            if(stack[top]=='{'){
                pop();
            }else{
                return 0;
            }
        }else if(arr[i]==']'){
            if(stack[top]=='['){
                pop();
            }else{
                return 0;
            }
        }
    }
    if(isEmpty()){
        return 1;
    }else
        return 0;
}
int main(){
    char arr[100];
    gets(arr);
    if(valid_parenthesis(arr)){
        printf("True\n");
    }else{
        printf("False\n");
    }
    return 0;
}