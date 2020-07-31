#include <stdio.h>

void enshu_3_8(char **argv,char *buffer){
    char ret[1024];
    int i=0;
    while(!(*argv==NULL)){ 
        int record=0;
        if(**argv=='-'){
            record==1;
        }
        while(!(**argv=='\0')){
            if(record==1){
        ret[i]=**argv;
        i++;
            }
        (*argv)++;
        }
        argv++;
    }


    
    ret[i]='\0';
    buffer=ret;
}

int main(){
    char *strv[] = { "000", "111", "222", "333" };
    char **pv = strv; 
    char a;
    enshu_3_8(pv,&a);
    printf("%c",a);

    return 0;
}