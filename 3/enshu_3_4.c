#include <stdio.h>
void swap(int *a, int *b){
if(!(a==NULL||b==NULL)){
        int tmp=*b;
        *b=*a;
        *a=tmp;
    }
}

void enshu_3_4(int array[10][10]){
    int i=0;
    int j=0;
    while(i<10){
        while(j<10){
            if(i<j){
        swap(&array[i][j],&array[j][i]);
            }
        j++;
        }
        j=0;
        i++;
    }
}

int main(){

    return 0;
}