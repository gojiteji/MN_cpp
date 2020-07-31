#include <stdio.h>

char *enshu_2_10(char *s,char *buff){
    if(buff==NULL)
        return NULL;
    if(s==NULL || *s=='\0'){
        *buff='\0';
        return buff;
    }
    int counter =0;

    while(*s != '\0'){
        s++;
        counter++;
    }
    s--;//don't use \0 as head.
    int counter2=counter;
    while(counter>0){
        *buff=*s;
        s--;
        buff++;
        counter --;
    }
    *buff='\0';
    while(counter2>1)
    {
        buff--;
        counter2 --;
    }
    return buff;
}

int main(){
    char *p1="redrum";
    char *p2="aaaaaa";
    char * rev;
    rev=enshu_2_10(p1,p2);
    while(rev!='\0'){
        printf("%d",*rev);
        rev++;
    }
    return 0;
}