#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
int precedence(char op){
    switch(op){
        case'+':
        case'-':
        return 1;
        case'*':
        case'/':
        return 2;
        case'^':
        return 3;
        default :
        return -1;
    }
}
char* infix_to_prefix(char *exp){
    char operator[100],outputstring[100];
    int len=strlen(exp), index=-1, top=-1;
    for(int i=len-1;i>=0;i--){
        char chr=exp[i];
        if(isalnum(chr)){
            outputstring[++index]=chr;
        }
        else if(chr=='+'||chr=='-'||chr=='*'||chr=='/'||chr=='^'){
            if(top==-1){
                operator[++top]=chr;
            }
            else{
                while(top!=-1 && precedence(chr)<=precedence(operator[top])){
                    outputstring[++index]=operator[top--];
                    
                }
                operator[++top]=chr;
            }
        }
        else if(chr==')'){
            operator[++top]=chr;
        }
        else if(chr=='('){
            while(operator[top]!=')'){
                outputstring[++index]=operator[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        outputstring[++index]=operator[top--];
    }
    outputstring[++index]='\0';
   int len1=strlen(outputstring);
   char*temp=(char*)malloc(len1+1);
   int j=0;
   for(int i=len1-1;i>=0;i--){
    temp[j++]=outputstring[i];
   }
   temp[j]='\0';
   return temp;
}
int main(){
    char exp[100];
    printf("Enter Infix Expression : ");
    gets(exp);
    printf( "Expression After Conversion is %s",infix_to_prefix(exp));
    return 0;
}