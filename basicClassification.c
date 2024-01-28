#include <stdio.h>
#include "NumClass.h"

int isPrime(int n){
    for (int i = 2; i < n; i++)
    {
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

//private function that return the facturial of the given number 
int facturial(int number){
    if(number==0 || number==1){
        return 1;
    }
    else{
        return number*facturial(number-1);
    }
}

int isStrong(int n){
    int number =n;
    int sum=0;
    while(number!=0){
        sum += facturial(number%10);
        number /=10;
    }
    if(sum==n){return 1;}
    return 0;
}