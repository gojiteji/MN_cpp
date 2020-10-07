#include <stdio.h>
#include <string.h>

typedef struct {
 int count;
 char *word;
} WordHolder; 



void enshu_4_4(WordHolder wh[], int lpos, int rpos){
    int i=lpos;
    int j=rpos;
    int pivot=lpos;
    while(1){
        //until find larger left
        while(strcmp((wh[i].word),(wh[pivot].word))<0){i++;}
        //unti; find smaller right
        while(strcmp((wh[j].word),(wh[pivot].word))>0){j--;}
        if(i>=j){break;}
        //swap
        WordHolder  tmp = wh[i];
        wh[i]=wh[j];
        wh[j]=tmp;
        i++;
        j--;
        }
    //array on left
    if(i-lpos>=1){
        enshu_4_4( wh, lpos, i-1 );
    }
    //array on right
    if(rpos-j>=1){
        enshu_4_4( wh, j + 1, rpos );
    }
}

int main() {
int s=9;
    WordHolder wh[s];
    wh[0].word="visit";
    wh[1].word="hope";
    wh[2].word="admit";
    wh[3].word="manufacture";
    wh[4].word="tiger";
    wh[5].word="elephant";
    wh[6].word="lion";
    wh[7].word="giraf";
    wh[8].word="rabbit";

	int i=0;
	for(i;i<s;i++){
    printf("%s\n",wh[i].word);
}printf("\n");
    enshu_4_4(wh,0,s);
 	for(i=0;i<s;i++){
    printf("%s\n",wh[i].word);
}
	return 0;
}
