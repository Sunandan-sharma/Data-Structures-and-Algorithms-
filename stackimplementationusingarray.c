#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
int stack[MAX],top=-1;
int isEmpty(){
    return (top == -1) ? 1 : 0;
}
int isFull(){
    return (top == MAX-1) ? 1 : 0;
}
void push(){
    if(isFull()){
        printf("Stack Overflow!!!!!\n");
        return;
    } else{
        int val;
        printf("Enter the element you want to insert : ");
        scanf("%d",&val);
        top++;
        stack[top]=val;
        printf("Element added !!!!\n");
    }
}
int pop(){
    if(isEmpty()){
        printf("Stack Underflow!!!!!\n");
        return INT_MIN;
    } else{
        int val=stack[top];
        top--;
        return val;
    }
}
int peek(){
    if(isEmpty()){
        printf("Stack is Empty!!!!!\n");
        return INT_MIN;
    }else{
        return stack[top];
    }
}
// not correct way to traverse stack but its tells how stack is stored in memory
void show(){
    if(isEmpty()){
        printf("Stack is empty");
    } else{
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main(){
    int choice;
    while(1){
        printf("\n1.Push Operation\n2.Pop Operation\n3.Peek Operation\n4.Show\n5.Exit\n");
        printf("Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            if(pop()!=INT_MIN){
                printf("%d is pop from the stack\n",pop());
            }
            break;
            case 3:
            if(peek()!=INT_MIN){
                printf("%d is topmost element of stack\n",peek());
            }
            break;
            case 4:
            show();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid Choice. Try Again!!!\n");
        }
        printf("\n");
        system("pause");
    }
    return 0;
}