#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * enshu_4_5(char **argv){
    int i=0;

    int l=0;
    while(1){
        if(*argv==NULL){
            break;
        }
        argv++;
        l++;
    }
    argv=argv-l;
    char *buffer = malloc(l + 1);
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
    char *a;    
     char *strv[] = { "000", "-111", "222", "333" };
    char **pv = strv; 
    a=enshu_4_5(pv);
    printf("%s",a);

    return 0;
}

    © 2020 GitHub, Inc.
    Terms
    Privacy
    Security
    Status
    Help
    Contact GitHub
    Pricing
    API
    Training
    Blog
    About


