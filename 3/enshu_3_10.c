#include<stdio.h>
#include<string.h>

int enshu_3_10(char *s1, char *s2){
    if(s1 == NULL && s2 == NULL) return 0;
    int min_len, s1_len = strlen(s1),s2_len = strlen(s2);
    if(s1_len < s2_len){
        min_len = s1_len;
    }else{
        min_len = s2_len;
    }
    int i;
    for(i=0;i<min_len;i++){
        if(*s1 == *s2){
            s1++;
            s2++;
            continue;
        }else{
            if(*s1 < *s2){
                return -1;
            }else{
                return 1;
            }
        }
    }
    return 0;
}