#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    
    if (strlen(s) % 2 != 0) return false;

    int stack[10000];
    int top = -1;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ')' && top > -1 && stack[top] == '(') top--;
        else if (s[i] == ']' && top > -1 && stack[top] == '[') top--;
        else if (s[i] == '}' && top > -1 && stack[top] == '{') top--;
        else 
        {
            stack[++top] = s[i];
        }
    }

    return top == -1;
}

int main()
{
    if (isValid("()")) printf("true");
    else printf("false");
}