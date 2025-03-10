#include<stdio.h>
#include<stdlib.h>
int stack[100],top=-1;
void push(){
    int val;
    scanf("%d",&val);
    top++;
    stack[top]=val;
}
void pop(){
        top--;
}
int main(){
     for(int i=0;i<3;i++){
         push();
     }
     pop();
     for(int i=0;i<2;i++){
         push();
     }
     for(int i=0;i<3;i++){
         pop();
     }
     for(int i=0;i<=top;i++){
            printf("%d ",stack[i]);
     }
     return 0;
}