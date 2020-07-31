#include <stdio.h>

int enshu_2_4(char ch, char s[]){
 if (s[0] == '\0')
 return 0;
 
 
 if(s[0] == ch){
 return 1 + enshu_2_4(ch,s + 1); 
 }else{
  return 0+ enshu_2_4(ch,s + 1); 
 }

}

int main(){
printf("%d",enshu_2_4('a',"aaba"));
    return 0;
}