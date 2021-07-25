#include <stdio.h>
#include <ctype.h>

typedef struct {
    char *wordptr;
    char *endptr;
    char word[16];
}  Wordtab;

Wordtab enshu_4_3(char *text)
{
    int i = 0;
    Wordtab ans = {NULL,NULL,};
    if(text == NULL){
        ans.wordptr = NULL;
        ans.endptr = NULL;
        ans.word[0] = '\0';
        return ans;
    }
    while(*text){
        if(isalpha(*text)){
            if(!isalpha(*(text-1))){
                ans.wordptr = text;
            }
            if(i < 15){
                ans.word[i] = *text;
                i++;
            }
            if(!isalpha(*(text+1))){
                ans.endptr = text + 1;
                ans.word[i] = '\0';
            }
        }
        text++;
        
    }
    return ans;
}

int main(void){
    char *text = "12abc34";
    Wordtab ans = enshu_4_3(text);
    printf("%s %s %s \n", ans.wordptr, ans.endptr, ans.word);
}