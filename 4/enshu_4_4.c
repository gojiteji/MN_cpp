#include <stdio.h>
#include <string.h>

typedef struct {
 int count;
 char *word;
} WordHolder; 

void enshu_4_4(WordHolder wh[], int lpos, int rpos){
    int i=lpos;
    while(1){
        int j=i+1;
        while(1){
            if(j==rpos)
                break;
            if(strcmp((wh[i].word),(wh[j].word))>0){
                char * tmp = wh[i].word;
                wh[i].word=wh[j].word;
                wh[j].word=tmp;
            }
        }
        if(i==rpos)
            break;
        i++;
    }
    
}

int main() {
    
	return 0;
}
