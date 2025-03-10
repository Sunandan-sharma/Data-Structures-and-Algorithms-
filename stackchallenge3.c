#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int stack[n],top=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&stack[i]);
        top++;
    }
    for(int i=1;i<n;i++){
        int key=stack[i];
        int j=i-1;
        while(j>=0 && stack[j]<key){
            stack[j+1]=stack[j];
            j--;
        }
        stack[j+1]=key;
    }
    for(int i=0;i<n;i++){
        printf("%d ",stack[i]);
    }
    return 0;
}