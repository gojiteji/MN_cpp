#include <stdio.h>
void enshu_3_7(double mat1[10][10], double mat2[10][10],double res[10][10]){

    int i=0;
    while(i<10){
            int j=0;
        while(j<10){
            res[i][j]=0;
            int k=0;
                    while(k<10){
        res[i][j]+=mat1[i][k]*mat2[k][j];
        k++;
                                }
        j++;
    }
    i++;
    }
}


int main(){
    double mat[10][10]={{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1},{1,2,3,1,2,3,1,2,3,1}};
    enshu_3_7(mat,mat,mat);
        for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
    printf("[%f]",mat[i][j]);
    }
    printf("\n");
    }
    return 0;
}