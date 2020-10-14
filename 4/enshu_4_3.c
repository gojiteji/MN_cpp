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
		text++;
			if(i>14){//longer tha 14
			while(1){
			if(isalpha(*text)){
					text++;			
				}else{
	         		w.endptr=text;				
					break;				
				}
			}
			}else{
			    w.endptr=text;
			}
			if(cont==0){
			    w.endptr=NULL;
			}
	        w.word[i]='\0';
	        return w;
        }
	//printf("%a\n",text);
        text++;
    }
}


int main() {
    char* inpt="AEDHTBEeondonbopXrlGD";
    Wordtab txt=enshu_4_3(inpt);
    printf("in   :%s\n",inpt);
    printf("out  :%s\n",txt.word);
	if(txt.wordptr==NULL){
    printf("head :%s\n",txt.wordptr);	
	}else{
    printf("head :%c,%a\n",*txt.wordptr,txt.wordptr);
	}
	if(txt.endptr==NULL){
    printf("tail :%s\n",txt.endptr);	
	}else{
    printf("tail :%c,%a\n",*txt.endptr,txt.endptr);
	}
	printf("\n");

    inpt="     NNNMMMWWW  ";
    txt=enshu_4_3(inpt);
    printf("in   :%s\n",inpt);
    printf("out  :%s\n",txt.word);
	if(txt.wordptr==NULL){
    printf("head :%s\n",txt.wordptr);	
	}else{
    printf("head :%c,%a\n",*txt.wordptr,txt.wordptr);
	}
	if(txt.endptr==NULL){
    printf("tail :%s\n",txt.endptr);	
	}else{
    printf("tail :%c,%a\n",*txt.endptr,txt.endptr);
	}
		
		printf("\n");

    inpt="";
    txt=enshu_4_3(inpt);
    printf("in   :%s\n",inpt);
    printf("out  :%s\n",txt.word);
	if(txt.wordptr==NULL){
    printf("head :%s\n",txt.wordptr);	
	}else{
    printf("head :%c,%a\n",*txt.wordptr,txt.wordptr);
	}
	if(txt.endptr==NULL){
    printf("tail :%s\n",txt.endptr);	
	}else{
    printf("tail :%c,%a\n",*txt.endptr,txt.endptr);
	}

		printf("\n");

    inpt="!@#$%^&*(){}|~<><>1234567890[]/?=+;:`";
    txt=enshu_4_3(inpt);
    printf("in   :%s\n",inpt);
    printf("out  :%s\n",txt.word);
	if(txt.wordptr==NULL){
    printf("head :%s\n",txt.wordptr);	
	}else{
    printf("head :%c,%a\n",*txt.wordptr,txt.wordptr);
	}
	if(txt.endptr==NULL){
    printf("tail :%s\n",txt.endptr);	
	}else{
    printf("tail :%c,%a\n",*txt.endptr,txt.endptr);
	}

    return 0;
}

