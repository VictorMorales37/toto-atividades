#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    
    char *commonPrefix = malloc(200);
    
    commonPrefix[0] = '\0';
    
    int allMatch = 1;

    for (int letra = 0; letra < 200; letra++) {
        allMatch = 1;
        for (int palavra = 0; palavra < strsSize; palavra++) {
            if (strs[0][letra] != strs[palavra][letra] || strs[0][letra] == '\0') {
                allMatch = 0;
                break;
            }
        }
        if (allMatch) {
            commonPrefix[letra] = strs[0][letra];
            commonPrefix[letra + 1] = '\0';
        }
        else {
            commonPrefix[letra] = '\0';
            break;
        }
    }
    return commonPrefix;
}

int main() {
 
    char* strs[] = {"flower", "flow", "flight"};
    char* result = longestCommonPrefix(strs, 3);
 
    printf("%s\n", result);
 
    free(result);
 
    return 0;
}