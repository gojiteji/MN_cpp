#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct wordlist {
 char *word;
 struct wordlist *next;
} WordList;
    
WordList *enshu_4_6(char **argv){
    WordList *head=argv;
    int i=0;
    WordList *ret;
    WordList *buffer = malloc(strlen(*argv) + 1);
    if(buffer==NULL)
        return NULL;

    WordList *buffer2 = malloc(strlen(*argv) + 1);
    if(buffer2==NULL)
        return NULL;

    while(1){
        WordList *w;
        while(1){
            while(1){
            //•¶Žš‚ÌƒRƒs[
            w->word=*argv;
            (*w->word)++;
            (*argv)++;
            }
        }
        w->next=argv+1;
        buffer=w;
        buffer++;
        i++;
        argv++;//ŽŸ‚Ì•¶Žš—ñ
        if(argv==NULL){
            buffer->next=NULL;
            buffer=buffer-i;
            break;
        }
    }
            while(1){
                buffer2=buffer;
                if(buffer==head){
                    return buffer2-i;
                }
                buffer2++;
                buffer--;
        }
}


int main(){
    return 0;
}