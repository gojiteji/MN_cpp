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
    if(text == NULL || text == "" || text == '\0'){
        return w;
    }
    int i=0;
    int cont=0;
    while(1){//後ろのループ
        if(isalpha(*text)){
            if(cont==0){//初めてのalphabet
                w.wordptr=text;
            }

            w.word[i]=*text;
            i++;
            cont=1;
        }

        if(((cont==1) && (isalpha(*text)==0))||(i>14)||(*text=='\0')){//続いててalphabet以外がでたら		
		text--;
            w.endptr=(text);
	        w.word[i]='\0';
	       
	        return w;
        }
        text++;
    }
}


int main() {
    Wordtab txt=enshu_4_3("23198aknvkornaaeafrafergaeg90u90vap");
    char * tmp="main output is:";
    printf("%s",tmp);
    printf("\n%s",txt.word);
    return 0;
}
