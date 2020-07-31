#include <stdio.h>

int enshu_2_5(char s[]){
    int l=0;
    if (s[0] == '\0')
         return 0;
    l += 1 + enshu_2_5( s+1);
    printf("%c",s[0]);
return l;
}

int main(){
    printf("%d",enshu_2_5("redrum"));
    return 0;
}


