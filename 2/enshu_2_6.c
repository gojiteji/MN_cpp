#include <stdio.h>

int  enshu_2_6(char *s){
int len = 0; 
for  (;;) {
    if(*s == '\0')
    break;
 len++;
 s++;
 }
 return len; 
}

int main(){
printf("%d",enshu_2_6("redrum"));
    return 0;
}