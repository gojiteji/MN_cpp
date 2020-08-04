#include <stdio.h>
#include <string.h>


void enshu_3_8(char **argv,char *buffer){
    char ret[1024];
    int i=0;
    while(!(*argv==NULL)){ 
        while(!(**argv=='\0')){
        //*buffer=**argv;
        if(!(**argv=='\n')){
        ret[i]=**argv;
                i++;
        }
        (*argv)++;
        }
        argv++;
    }

    ret[i]='\0';

    buffer=ret;
    i=0;
    while(!(ret[i]=='\0')){
    strcpy(buffer, ret[i]);
    buffer++;
    i++;
    }
    
printf("%a,has,",buffer);
printf("%c",*buffer);

}
int main(){

    char *a;    
     char *strv[] = { "000", "-111", "222", "333" };
    char **pv = strv; 
    enshu_3_8(pv,&a);
    printf("%a,has,",a);


    return 0;
}