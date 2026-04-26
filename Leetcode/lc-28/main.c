#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    
    int hayLen = strlen(haystack);
    int neeLen = strlen(needle);
    int index = -1;
    int buf = 0;
    bool found = false;

    if (hayLen < neeLen) return -1;

    for (int i = 0; i < hayLen; i++)
    {
        if (haystack[i] == needle[buf])
        {
            if (buf == 0) index = i;
            if (buf == neeLen-1) 
            {
                found = true;
                break;
            }

            buf++;
        } 
        
        else 
        {
            if (buf != 0) i -= buf;
            buf = 0;
            index = -1;    
        }
    }

    if (found) return index;
    else return -1;
}

int main() {
    printf("%d\n", strStr("hello", "ll"));
    return 0;
}