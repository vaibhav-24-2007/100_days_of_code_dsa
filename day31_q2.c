#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c)
{
    top++;
    stack[top] = c;
}

char pop()
{
    if(top == -1)
        return '#';
    char c = stack[top];
    top--;
    return c;
}

int main()
{
    char s[100];
    scanf("%s", s);

    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else
        {
            char x = pop();

            if((s[i] == ')' && x != '(') ||
               (s[i] == '}' && x != '{') ||
               (s[i] == ']' && x != '['))
            {
                printf("Invalid");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("Valid");
    else
        printf("Invalid");

    return 0;
}
