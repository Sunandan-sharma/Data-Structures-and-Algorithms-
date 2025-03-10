#include <stdio.h>
#include <string.h>
#include <math.h>
#include<ctype.h> 
int operand[100],top1=-1;
int prefix_Evaluation(char *exp){
    int len=strlen(exp);
    for(int i=len-1;i>=0;i--){
        char ch=exp[i];
        if(isdigit(ch)){
            int num=0,base=1;
            while(i>=0 && isdigit(exp[i])){
                num=num+(exp[i]-'0')*base;
                base*=10;
                i--;
            }
            i++;
            operand[++top1]=num;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            int z;
            int x=operand[top1--];
            int y=operand[top1--];
            char opr=ch;
            switch(opr){
                case'+':
                z=y+x;
                break;
                case'-':
                z=y-x;
                break;
                case'*':
                z=y*x;
                break;
                case'/':
                z=y/x;
                break;
                case'^':
                z=pow(y,x);
                break;
            }
            operand[++top1]=z;
        }     
    }
    return operand[top1--];
}
int main(){
    char exp[100];
    printf("Enter Prefix Expression : ");
    gets(exp);
    printf("Result : %d\n",prefix_Evaluation(exp));
    return 0;
}
