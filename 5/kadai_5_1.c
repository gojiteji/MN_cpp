#include <stdio.h>
#include <stdlib.h>

typedef struct wordlist {
    char *eng;
    char *jpn;
    struct wordlist *next;
} WordList;

unsigned int kadai_5_1_hash(char *str){
	if((str==NULL) ||( *str=='\0')){
		return 0;
	}
	int hash=0;
	while(1){
		int add = (int)(*str);
		hash=hash+(add%127);
		if(*(str+1)=='\0'){
			break;
		}else{
			hash=hash*256;
			str++;
		}
	}
	return hash%127;
}

char *kadai_5_1_search(WordList *dictionary[], char*keyword){
	if(dictionary[kadai_5_1_hash(keyword)]==NULL){
	return NULL;
	}
	WordList *w=dictionary[kadai_5_1_hash(keyword)];
	while(1){
		if(w->eng==keyword){
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
	
	if(dictionary[kadai_5_1_hash(e_word)]==NULL){
		dictionary[kadai_5_1_hash(e_word)]=tmp;
	}else{
		WordList *next=dictionary[kadai_5_1_hash(e_word)]->next;
		while(1){
			if(next->next==NULL){
				break;
			}
			next=next->next;
		}
		dictionary[kadai_5_1_hash(e_word)]->next=tmp;
	}
}

int main(){
	WordList *w[128];
	kadai_5_1_append(w,"hello","おはよう");
	printf("%s",kadai_5_1_search(w,"hello"));
	return 0;
}




