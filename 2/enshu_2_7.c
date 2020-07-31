#include <stdio.h>

int enshu_2_7(char ch, char *s){
    int counter=0;
 while (*s != '\0') {
 if (*s == ch)
    counter++;
 s++;
 } 
 return counter;
}

int main(){
printf("%d",enshu_2_7('r',"redrum"));
    return 0;
}