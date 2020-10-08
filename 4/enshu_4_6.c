#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct wordlist {
 char *word;
 struct wordlist *next;
} WordList;
    
WordList *enshu_4_6(char **argv){
    int l=0;
    while(1){
        if(*argv==NULL){
            break;
        }
        argv++;
        l++;
    }
    WordList *tmp = malloc(sizeof(WordList));
    tmp->next=NULL;
    (tmp->word)=*argv;
    l--;
    argv--;
    while(l>=0){
    WordList *tmp2 = malloc(sizeof(WordList));
    tmp2->next=tmp;
    (tmp2->word)=*argv;
    l--;
    argv--;
    tmp=tmp2;
    }
    return tmp;
}


int main(){
    WordList *a;    
    char *strv[] = { "dog", "cat", "lion", "sheep","dog", "cat", "lion", "sheep" ,"dog", "cat", "lion", "sheep","dog", "cat", "lion", "sheep" };
    char **pv = strv; 
    a=enshu_4_6(pv);
    while(a->next!=NULL){
	printf("%s\n",a->word);
	a=a->next;
     }
    return 0;
}
