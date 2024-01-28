/*#include <stdio.h>
#include <stdbool.h>
#include "NumClass.h"

bool isArmstrong(int n, int original, int count) {
    if (n == 0) {
        return original == 0; 
    }

    return (n % 10) ^ count + isArmstrong(n / 10, original, count) == original;
}

bool isPalindromeHelper(int number, int original, int count) {
    if (count == 0) {
        return true;
    }

    int lastDigit = number % 10;
    int power = 1;
    

    for (int i = 1; i < count; i++) {
        power *= 10;
    }

    int firstDigit = original / power;

    if (firstDigit != lastDigit) {
        return false;
    }

    return isPalindromeHelper(number / 10, original % power, count - 2);
}

bool isPalindrome(int n) {
    int count = 0;
    int temp = n;

    while (temp != 0) {
        temp /= 10;
        count++;
    }

    if(count==0){
        return true;
    }

    return isPalindromeHelper(n, n, count);
}
*/

#include <stdio.h>
#include "NumClass.h"

/*int isArmstrong(int n, int original, int count) {
    if (n == 0) {
        return original == 0; 
    }

    return (n % 10) + isArmstrong(n / 10, original, count) == original;
}*/
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}

int countDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + countDigits(n / 10);
}

int isArmstrongRecursive(int n, int originalNumber, int count) {
    if (count == 0) {
        return n == originalNumber;
    }

    int digit = n % 10;
    return power(digit, count) + isArmstrongRecursive(n / 10, originalNumber, count - 1);
}

int isArmstrong(int n) {
    int count = countDigits(n);
    return isArmstrongRecursive(n, n, count) == n;
}


int isPalindromeHelper(int number, int original, int count) {
    if (count == 0) {
        return 1;
    }

    int lastDigit = number % 10;
    int power = 1;
    
    for (int i = 1; i < count; i++) {
        power *= 10;
    }

    int firstDigit = original / power;

    if (firstDigit != lastDigit) {
        return 0;
    }

    return isPalindromeHelper(number / 10, original % power, count - 2);
}

int isPalindrome(int n) {
    int count = 0;
    int temp = n;

    while (temp != 0) {
        temp /= 10;
        count++;
    }

    if (count == 0) {
        // Handle the case where n is 0 separately, as it doesn't have any digits.
        return 1;
    }

    return isPalindromeHelper(n, n, count);
}