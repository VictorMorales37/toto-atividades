#include <stdio.h>
#include <stdbool.h>

bool LemonadeChange( int* bills, int billsSize ) {
    
    int fives = 0;
    int tens = 0;

    for ( int i = 0; i < billsSize; i++ ) {
        
        if ( bills[i] == 5 ) {
            fives += 1;
        }

        if ( bills[i] == 10 ) {
            if ( fives == 0 ) { 
                return false;
            }
            fives -= 1;
            tens += 1;
        }

        if ( bills[i] == 20 ) {
            if ( tens > 0 && fives > 0 ) 
            {
                tens -= 1;
                fives -= 1;
            } else if ( fives >= 3 ) {
                fives -= 3;             
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    
    int bills[5] = {5, 5, 10, 10, 20};
    
    if ( LemonadeChange(bills, 5) ) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}
