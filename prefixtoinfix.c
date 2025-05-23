#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char *prefix_to_infix(char *exp){
    int size=strlen(exp),top=-1;
    char stack[size][100];
    for(int i=size-1;i>=0;i--){
        char ch=exp[i];
        if(isalnum(ch)){
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            char *s1=stack[top--];
            char *s2=stack[top--];
            char s3[100];
            snprintf(s3,100,"(%s%c%s)",s1,ch,s2);
            strcpy(stack[++top],s3);
        }
    }
    char *s=(char*)malloc(strlen(stack[top]+1));
    strcpy(s,stack[top]);
    return s;
}
int main(){
    char exp[100];
    printf("Enter Prefix Expression : ");
    gets(exp);
    printf("After Conversion Expression is : %s",prefix_to_infix(exp));
    return 0;
}