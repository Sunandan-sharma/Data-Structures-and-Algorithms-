#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX],top1=-1,top2=MAX;
int isstack1Empty(){
    return (top1 == -1) ? 1 : 0;
}
int isstack2Empty(){
    return (top2 == MAX) ? 1 : 0;
}
int isstack1Full(){
    return (top1 == top2-1) ? 1 : 0;
}
int isstack2Full(){
    return (top2 == top1+1) ? 1 : 0;
}
void pushstack1(){
    if(isstack1Full()){
        printf("Stack Overflow!!!!\n");
        return;
    } else{
        int value;
        printf("Enter element to push : ");
        scanf("%d",&value);
        stack[++top1]=value;
        printf("Element Added!!!\n");
    }
    printf("\n");
}
void pushstack2(){
    if(isstack2Full()){
        printf("Stack Overflow!!!!\n");
        return;
    } else{
        int val;
        printf("Enter element to push : ");
        scanf("%d",&val);
        stack[--top2]=val;
        printf("Element Added!!!\n");
    }
    printf("\n");
}
void popstack1(){
    if(isstack1Empty()){
        printf("Stack Underflow!!!!\n");
        return;
    }
    else{
    int val=stack[top1];
    top1--;
    printf("Element popped %d\n",val);
    }
    printf("\n");
}
void popstack2(){
    if(isstack2Empty()){
        printf("Stack Underflow!!!!\n");
        return;
    }
    else{
    int val1=stack[top2];
    top2++;
    printf("Element popped %d\n",val1);
    }
    printf("\n");
}
void peekstack1(){
    if(isstack1Empty()){
        printf("Stack Is Empty!!!\n");
        return;
    } else{
    int val1=stack[top1];
    printf("The topmost value of stack is %d",val1);
}
printf("\n");
}
void peekstack2(){
    if(isstack2Empty()){
        printf("Stack Is Empty!!!\n");
        return;
    } else{
    int val2=stack[top2];
    printf("The topmost value of stack is %d",val2);
}
printf("\n");
}
void showstack1(){
    if(isstack1Empty()){
        printf("Stack Is Empty!!!\n");
        return;
    } else
    for(int i=top1;i>=0;i--){
        printf("%d",stack[i]);
    }
    printf("\n");
}
void showstack2(){
    if(isstack2Empty()){
        printf("Stack Is Empty!!!\n");
        return;
    } else
    for(int i=top2;i<MAX;i++){
        printf("%d",stack[i]);
    }
    printf("\n");
}
int main(){
    int choice;
    while(1){
        printf("1.Push element in stack1\n2.Push element in stack2\n");
        printf("3.pop element from stack1\n4.pop element from stack2\n");
        printf("5.Peek element from stack1\n6.Peek element from stack2\n");
        printf("7.Display elements of stack1\n8.Display elements of stack2\n");
        printf("9.Exit\n");
        printf("Your Choce : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            pushstack1();
            break;
            case 2:
            pushstack2();
            break;
            case 3:
            popstack1();
            break;
            case 4:
            popstack2();
            break;
            case 5:
            peekstack1();
            break;
            case 6:
            peekstack2();
            break;
            case 7:
            showstack1();
            break;
            case 8:
            showstack2();
            break;
            case 9:
            exit(0);
            default:
            printf("Invalid Choice!!!!\n");
        }
    }
    return 0;
}