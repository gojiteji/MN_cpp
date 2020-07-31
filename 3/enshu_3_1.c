#include <stdio.h>
#include <math.h>
#define M_P 3.14159265358979323846264338327


int enshu_3_1(double values[2][91]){
    int i=0;
    while(i<91){

        values[0][i]=sin(2*M_P*i/360);
        values[1][i]=cos(2*M_P*i/360);
        i++;
    }
    return values;
}


int main(){
    
    return 0;
}