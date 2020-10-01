#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * enshu_4_5(char **argv){
    int i=0;
    char *buffer = malloc(strlen(*argv) + 1);
    if(buffer==NULL)
        return NULL;
    while(!(*argv==NULL)){ 
        while(!(**argv=='\0')){
        strcpy(buffer,*argv);
        buffer++;
        i++;
        (*argv)++;
        }
        argv++;
    }

    *buffer='\0';
    

    buffer=buffer -i;
    return buffer;


}
int main(){


    return 0;
}