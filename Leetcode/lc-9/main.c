#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPalindrome(int x) {

    if (x < 0) {
        return false;
    }

    int numOfDigits = 1;

    for (int d = 1; x > pow(10, d) - 1;) {
        numOfDigits += 1;
        d++;
    }

    int digits[numOfDigits];

    for (int i = 0; i < numOfDigits; i++) {
        digits[i] = (int)(x / pow(10, i)) % 10;
    }

    for (int i = 0; i < numOfDigits; i++) {
        if (digits[i] != digits[(numOfDigits - i) - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("%d\n", isPalindrome(121));
    return 0;
}