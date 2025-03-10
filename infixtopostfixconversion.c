#include<stdio.h>
#include<string.h>
#include<ctype.h>
char operator[100],outputstring[100];
int top=-1,index=-1;
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
char* infix_to_postfix(char *exp){
    for(int i=0;exp[i]!='\0';i++){
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
        else if(chr=='('){
            operator[++top]=chr;
        }
        else if(chr==')'){
            while(operator[top]!='('){
                outputstring[++index]=operator[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        outputstring[++index]=operator[top--];
    }
    outputstring[++index]='\0';
    return outputstring;
}
int main(){
    char exp[100];
    printf("Enter Infix Expression : ");
    gets(exp);
    printf( "Expression After Conversion is %s",infix_to_postfix(exp));
    return 0;
}