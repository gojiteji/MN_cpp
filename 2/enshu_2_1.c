#include <stdio.h>
int factorial(int n)
{
 int i;
 int fact = 1;
 for (i = 1; i <= n; i++) {
 fact *= i;
 }
 return fact;
}

int enshu_2_1(int begin, int  end){
    if(begin>end){
        return 0;
    }
    int i=begin;
    while(i<end+1){
        printf("%d! = %d\n",i,factorial(i));
        i=i+1;
    }
    
    return end-begin +1;
}


int main(){
    printf("%d",enshu_2_1(2,4));
    return 0;
}