#include <stdio.h>
#include <ctype.h>


typedef struct {
 char *wordptr;
 char *endptr;
 char word[16];
} Wordtab; 


Wordtab enshu_4_3(char*text){
    Wordtab w;
    w.wordptr=NULL;
    w.endptr=NULL;
    w.word[0]='\0';
    if(text == NULL){
        return w;
    }
    int i=0;
    int cont=0;
    while(1){//Œã‚ë‚Ìƒ‹[ƒv
        if(text=='\0'){
            break;
        }
        if(isalpha(*text)){
            if(cont==0){//‰‚ß‚Ä‚Ìalphabet
                w.wordptr==text;
            }
            w.word[i]=*text;
            i++;
            cont=1;
        }
        if(cont==1 && isalpha(*text)==0){//‘±‚¢‚Ä‚ÄalphabetˆÈŠO‚ª‚Å‚½‚ç
            w.endptr=text;
	        w.word[i]='\0';    
	        return w;
        }
        text++;
    }
    return w;
    
}


int main() {
    
	return 0;
}
