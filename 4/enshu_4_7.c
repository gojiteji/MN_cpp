#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct wordlist {
 char *word;
 struct wordlist *next;
} WordList;
    
WordList *enshu_4_7(WordList *wl){
    int l=0;
    WordList *t;
    t=wl;
    while(1){
        if(t->next==NULL){
            break;
        }
        t=t->next;
        l++;
    }
    WordList *tmp = malloc(sizeof(WordList));
    //WordList *wl2 = wl;
    //tmp->next=NULL;
    //(tmp->word)=wl->word;
    //l--;
    //wl2=wl->next;
    while(l>=0){
    WordList *tmp2 = malloc(sizeof(WordList));
    //tmp2->next=tmp;
    //(tmp2->word)=wl;
    l--;
    wl2=wl2->next;
    tmp=tmp2;
    }
    return tmp;
}


int main(){
    WordList *a;
    WordList *b;
    WordList *c;
    WordList *d;
    a->next=b;
    a->word="a";
    b->next=c;
    b->word="b";
    c->next=d;
    c->word="c";
    d->next=NULL;
    d->word="d";

    a=enshu_4_7(a);
    //printf("%s\n",a->word);
    //printf("%s\n",(a->next)->word);
    //printf("%s\n",((a->next)->next)->word);
    //printf("%s\n",(((a->next)->next)->next)->word);
    return 0;
}