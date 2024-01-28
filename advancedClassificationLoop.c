#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "NumClass.h"

int isPalindrome(int n) {
    int original = n;
    int reversed = 0;

    // Reverse the number
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    // Check if the reversed number is equal to the original
    if (original == reversed) {
        return 1; // It is a palindrome
    } else {
        return 0; // It is not a palindrome
    }
}

int countDigits(int n) {
    int count = 0;

    while (n != 0) {
        n /= 10;
        count++;
    }

    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int n) {
    int original = n;
    int numDigits = countDigits(n);
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, numDigits);
        n /= 10;
    }

    return (original == sum);
}
