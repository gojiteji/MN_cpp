#include <stdio.h>
#include <string.h>

typedef struct {
 int count;
 char *word;
} WordHolder; 


void enshu_4_4(WordHolder wh[], int lpos, int rpos){
    int i=lpos;
    int j=rpos;
    int center=(lpos+rpos)/2
    while(1){
        //Œğ·‚µ‚½‚çI—¹
        if(i=>j)
            break;
        //¶‚Ì‚Ù‚¤‚ª‘å‚«‚¢
        if(strcmp((wh[i].word),(wh[center].word))>0){
            //‰E‚Ì‚Ù‚¤‚ª¬‚³‚¢
            if(strcmp((wh[j].word),(wh[center].word))<0){
                char * tmp = wh[i].word;
                wh[i].word=wh[j].word;
                wh[j].word=tmp;
            }
        }
        i++;
        j--;
    }
        if(i==rpos)
            break;
        i++;
    }
    
}

int main() {
    
	return 0;
}
