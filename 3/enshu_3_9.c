#include <stdio.h>

void enshu_3_8(char **argv,char *buffer){
    char ret[1024];
    int i=0;
    int add=0;
    while(!(*argv==NULL)){ 
        if(**argv=='-'){
            add=1;
        }
        while(!(**argv=='\0')){
            if(add == 1 ){
        *buffer=**argv;
        i++;
        buffer++;
            }
        (*argv)++;
        }
        argv++;
    }


    
    buffer='\0';
    buffer -=i;
}

int main(){
    char *strv[] = { "000", "111", "222", "333" };
    char **pv = strv; 
    char *a;
    enshu_3_8(pv,&a);
    printf("%c",a);

    return 0;
}