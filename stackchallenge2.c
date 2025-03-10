#include <stdio.h>
#include <stdlib.h>
int stack[100], top = -1;
void push()
{
    int val;
    scanf("%d", &val);
    top++;
    stack[top] = val;
}
void pop()
{
    top--;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stack[i]);
        top++;
    }
    for (int i = 0; i < 2; i++)
    {
        pop();
    }
    for (int i = 0; i < 4; i++)
    {
        push();
    }
    pop();
    for (int i = 0; i < 2; i++)
    {
        push();
    }
    for (int i = 0; i < 3; i++)
    {
        pop();
    }
    for (int i =top; i >=0; i--)
    {
        printf("%d ", stack[i]);
    }
    return 0;
}