#include <stdio.h>
#include <string.h>

typedef struct {
 int count;
 char *word;
} WordHolder; 


void quicksort(WordHolder wh[], int lpos,int rpos){
    int i=lpos;
    int j=rpos;
    int pivot=(lpos+rpos)/2;
    while(1){
        //until find larger left
        while(strcmp((wh[i].word),(wh[pivot].word))<0){i++;}
        //unti; find smaller right
        while(strcmp((wh[j].word),(wh[pivot].word))>0){j--;}
        if(i>=j){break;}
        //swap
        char * tmp = wh[i].word;
        wh[i].word=wh[j].word;
        wh[j].word=tmp;
        i++;
        j++;
        }
    //array on left
    if(i-lpos>=2){
        quicksort( wh, lpos, i - 1 );
    }
    //array on right
    if(rpos-j>=2){
        quicksort( wh, j + 1, rpos );
    }
}

void enshu_4_4(WordHolder wh[], int lpos, int rpos){
    quicksort(wh,lpos,rpos);
}

int main() {
    WordHolder wh[4];
    wh[0].word="C";
    wh[1].word="B";
    wh[2].word="D";
    wh[3].word="C";
    printf("%s\n",wh[0].word);
    printf("%s\n",wh[1].word);
    printf("%s\n",wh[2].word);
    printf("%s\n\n",wh[3].word);
    enshu_4_4(wh,0,3);
    printf("%s\n",wh[0].word);
    printf("%s\n",wh[1].word);
    printf("%s\n",wh[2].word);
    printf("%s\n",wh[3].word);

	return 0;
}
