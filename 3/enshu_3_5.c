#include <stdio.h>
double enshu_3_5(double mat[3][3]){
    double aei=mat[0][0]*mat[1][1]*mat[2][2];
    double cdh=mat[0][2]*mat[1][0]*mat[2][1];
    double bfg=mat[0][1]*mat[1][2]*mat[2][0];
    double bdi=mat[0][1]*mat[1][0]*mat[2][2];
    double afh=mat[0][0]*mat[1][2]*mat[2][1];
    double ceg=mat[0][2]*mat[1][1]*mat[2][0];
return aei+cdh+bfg-bdi-afh-ceg;
}

int main(){

    return 0;
}