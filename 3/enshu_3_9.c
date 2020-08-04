#include <stdio.h>


void enshu_3_9(char **argv,char *buffer){
    char ret[1024];
    int i=0;
    if(!(argv==NULL)){
    while(!(*argv==NULL)){ 
        int head =1;
        int has_m=0;
        while(!(**argv=='\0')){
            if(head==1){
                head=0;
                if(!(**argv=='-')){
                    has_m=1;
                }
            }
        if(has_m=1){
        *buffer=**argv;
        i++;
            }
        (*argv)++;
        }
        argv++;
    }
    }

    *buffer='\0';

    buffer=buffer -i;


}
int main(){


    return 0;
}