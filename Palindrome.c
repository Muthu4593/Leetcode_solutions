#include <stdbool.h>

bool isPalindrome(int x) {
    
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedNum = 0;
    
    while (x > reversedNum) {
        int pop = x % 10;          
        reversedNum = (reversedNum * 10) + pop; 
        x /= 10;                   
    }

    // If length is odd, we can get rid of the middle digit by reversedNum / 10
    return x == reversedNum || x == reversedNum / 10;
}
