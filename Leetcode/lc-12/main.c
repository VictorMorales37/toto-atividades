#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {

    char* result = malloc(200);
    int index = -1;

    for (int i = 3000; i > 999; i -= 1000) 
    { 
        if (num >= i) 
        {
            int k = i / 1000;
            for (int j = 0; j < k; j++)
            {
                index++;
                result[index] = 'M';
            }
            num -= i;
            break;
        }
    }

    for (int i = 900; i > 99; i -= 100) 
    { 
        if (num >= i) 
        {
            if (i == 900)
            {
                index++;
                result[index] = 'C';
                index++;
                result[index] = 'M';
            }

            else if (i >= 500)
            {
                index++;
                result[index] = 'D';
                for (int j = 0; j < i/100 - 5; j++)
                {
                    index++;
                    result[index] = 'C';
                }
            }

            else if (i == 400)
            {
                index++;
                result[index] = 'C';
                index++;
                result[index] = 'D';
            }
            else
            {
                for (int j = 0; j < i / 100; j++)
                {
                    index++;
                    result[index] = 'C';
                }
            }
            num -= i;
            break;
        }
    }

    for (int i = 90; i > 9; i -= 10) 
    { 
        if (num >= i) 
        {
            if (i == 90)
            {
                index++;
                result[index] = 'X';
                index++;
                result[index] = 'C';
            }

            else if (i >= 50)
            {
                index++;
                result[index] = 'L';
                for (int j = 0; j < i/10 - 5; j++)
                {
                    index++;
                    result[index] = 'X';
                }
            }

            else if (i == 40)
            {
                index++;
                result[index] = 'X';
                index++;
                result[index] = 'L';
            }
            else
            {
                for (int j = 0; j < i / 10; j++)
                {
                    index++;
                    result[index] = 'X';
                }
            }
            num -= i;
            break;
        }
    }

    for (int i = 9; i > 0; i -= 1) 
    { 
        if (num >= i) 
        {
            if (i == 9)
            {
                index++;
                result[index] = 'I';
                index++;
                result[index] = 'X';
            }

            else if (i >= 5)
            {
                index++;
                result[index] = 'V';
                for (int j = 0; j < i - 5; j++)
                {
                    index++;
                    result[index] = 'I';
                }
            }

            else if (i == 4)
            {
                index++;
                result[index] = 'I';
                index++;
                result[index] = 'V';
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    index++;
                    result[index] = 'I';
                }
            }
            num -= i;
            break;
        }
    }

    index++;
    result[index] = '\0';
    return result;
}

int main() {
    char* result = intToRoman(1994);
    printf("%s\n", result);
    free(result);
    return 0;
}