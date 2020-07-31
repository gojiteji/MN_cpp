#include <stdio.h>


void enshu_3_3(int *a, int *b){
if(!(a==NULL||b==NULL)){
        int tmp=*b;
        *b=*a;
        *a=tmp;
}

}

int main(){
    int a=100;
    int b=2;
    enshu_3_3(&a,&b);
    printf("%d,%d",a,b);
    return 0;
}