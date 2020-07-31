#include <stdio.h>
int enshu_2_3(int n){
if (n == 0)
     return 0;
return n + enshu_2_3(n - 1);
}

int  main (){
    printf("%d",enshu_2_3(10));
    return 0;
}