#include <stdio.h>

char *enshu_2_8(char ch, char *s){
    char *adr;
    int has =0;
 while (*s != '\0') {
 if (*s == ch){
    adr=s;
    has =1;
 }
 s++;
 } 
 if(has==1){
     return adr;
 }else{
     return NULL;
 }
}

int main(){
    char ch='a';
    char *s="redrum";
    char *adr=enshu_2_8('e',"redrum");
    printf("%s",adr);
    return 0;
}