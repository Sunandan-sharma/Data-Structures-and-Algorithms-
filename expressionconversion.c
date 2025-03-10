#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
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
    char operator[100],outputstring[100];
    int top=-1,index=-1;
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
    char *s=(char*)malloc(strlen(outputstring)+1);
    strcpy(s,outputstring);
    return s;
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
    strrev(outputstring);
    char *s=(char*)malloc(strlen(outputstring)+1);
    strcpy(s,outputstring);
    return s;
}
char * postfix_to_infix(char *exp){
    int size=strlen(exp),top=-1;
    char stack[size][100];
    for(int i=0;exp[i]!='\0';i++){
        char ch=exp[i];
        if(isalnum(ch)){
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
        char *s1=stack[top--];
        char *s2=stack[top--];
        char s3[100];
        snprintf(s3,100,"(%s%c%s)",s2,ch,s1);
        strcpy(stack[++top],s3);
    }
}
char *s=(char*)malloc(strlen(stack[top]+1));
strcpy(s,stack[top]);
return s;
}
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
    printf("Enter Infix Expression : ");
    gets(exp);
    printf( "Expression After Conversion is %s\n",infix_to_postfix(exp));
    printf("Enter Infix Expression : ");
    gets(exp);
    printf( "Expression After Conversion is %s\n",infix_to_prefix(exp));
    printf("Enter postfix Expression :");
    gets(exp);
    printf("Expression after coversion is  :%s\n ",postfix_to_infix(exp));
    printf("Enter Prefix Expression : ");
    gets(exp);
    printf("After Conversion Expression is : %s\n",prefix_to_infix(exp));
    return 0;
}