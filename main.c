#include "NumClass.h"
#include "basicClassification.c"
#include "advancedClassificationLoop.c"
#include<stdbool.h>
#include <stdio.h>

int main(){
    int a;
    int b;
    printf("enter the first number :");
    scanf("%d" , &a);
    printf("enter the second number:");
    scanf("%d",&b);

    printf("The Armstrong numbers are:");
    for (int i = a; i <= b; i++) {
        if (isArmstrong(i)==1) {
            printf(" %d", i);
        }
    }
    printf("\n");
    printf("The Palindromes are:");
    for (int i = a; i <= b; i++) {
        if (isPalindrome(i)==1) {
            printf(" %d", i);
        }
    }
    printf("\n");
    printf("The Prime numbers are:");
    for (int i = a; i <= b; i++) {
        if (isPrime(i)==1) {
            printf(" %d", i);
        }
    }
    printf("\n");
    printf("The Strong numbers are:");
    for (int i = a; i <= b; i++) {
        if (isStrong(i)==1) {
            printf(" %d", i);
        }
    }

    return 0;
}