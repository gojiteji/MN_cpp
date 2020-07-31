#include <stdio.h>
int enshu_2_2(int n){
if (n == 0)
     return 0;
return n + enshu_2_2(n - 1);
}

int  main (){
    printf("%d",enshu_2_2(1000));
    return 0;
}