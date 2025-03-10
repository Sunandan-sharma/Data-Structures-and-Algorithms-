#include<stdio.h>
#include<stdlib.h>
void remove_adjacent(char *str){
    int top=-1;
    for(int i=0;str[i]!='\0';i++){
        if(top>=0 && str[top]==str[i]){
            top--;
        }else{
        top++;
        str[top]=str[i];
        }
    }
    str[top+1]='\0';
    printf("%s",str);
}
int main(){
    char str[100];
    gets(str);
    remove_adjacent(str);
    return 0;
}