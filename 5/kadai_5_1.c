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
	int add = (int)(*str);
	add = add%127;//first cycle only 
	while(1){
		if(*(str+1)=='\0'){
			hash=hash+add;
			break;
		}else{
			hash=hash+add*256;
			str++;
			add = (int)(*str);
			add = add%127;
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
	//WordList *w[128];
	//kadai_5_1_append(w,"hello","おはよう");
	printf("%d",kadai_5_1_hash("hello"));
	return 0;
}




