#include <stdio.h>
#include <math.h>
#define M_P 3.14159265358979323846264338327

void enshu_3_2(int k, double values[65]){
    int i=0;
    while(i<65){
        double sum=0.;
        int n=0;
        while(n<k){
         sum+=(4/M_P)*sin((2*n+1)*M_P*i/32)/(2*n+1);
        n++;
    }
    values[i]=sum;
        i++;
}
}
    

int main(){
    printf("workng");
    return 0;
}