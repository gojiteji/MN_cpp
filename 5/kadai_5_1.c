#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct wordlist {
    char *eng;
    char *jpn;
    struct wordlist *next;
} WordList;

/*
"represent":70

*/
unsigned int kadai_5_1_hash(char *str){
	if((str==NULL) ||( *str=='\0')){
		return 0;
	}
	int hash=0;
	int add = (int)(*str);
	add = add%127;//first cycle only 
	hash=hash+add;
	while(1){
		if(*(str+1)=='\0'){
			break;
		}else{
			str++;
			hash=hash*256;//upper digit
			add = (int)(*str);
			hash =hash+add;
			hash=(hash)%127;
		}
	}
	return hash;
}

char *kadai_5_1_search(WordList *dictionary[], char*keyword){
	if(dictionary[kadai_5_1_hash(keyword)]==NULL){
	return NULL;
	}
	WordList *w=dictionary[kadai_5_1_hash(keyword)];
	while(1){
        if(strcmp(w->eng,keyword)==0){
    		printf(NULL);
		    printf(NULL);
            return w->jpn;
        }
		//couldn't find
		if(w->next==NULL){
		return NULL;		
		}

		w=w->next;
	}
}

void kadai_5_1_append(WordList *dictionary[], char *e_word,char *j_word){
	WordList *tmp = malloc(sizeof(WordList));
	tmp->eng=e_word;
	tmp->jpn=j_word;
	tmp->next=NULL;
	if(dictionary[kadai_5_1_hash(e_word)]==NULL){//new hash number
		dictionary[kadai_5_1_hash(e_word)]=tmp;
	}else{                                       //existing hash number
		WordList *head=dictionary[kadai_5_1_hash(e_word)];
		//go to the end of a same number of  the wordlist.
		while(head->next!=NULL){
			    head=head->next;
		}
		head->next=tmp;
		printf(NULL);
		printf(NULL);
	}
}

int main(){
	WordList *w[128];
	kadai_5_1_append(w,"represent","代表する");
	kadai_5_1_append(w,"googlV","ほげほげ");
	kadai_5_1_append(w,"F","エフ");

	printf("hash:%d\n",kadai_5_1_hash("represent"));
	if(kadai_5_1_search(w,"represent")!=NULL){
    	printf("%s",kadai_5_1_search(w,"represent"));
	}else{
	    printf("\n%s","search null");
	}
	return 0;
}




