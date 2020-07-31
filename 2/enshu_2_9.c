#include <stdio.h>
char *enshu_2_9(int score){
    char *str;
    char *A="Terrible!";
    char *B="Bad";
    char *C="Good";
    char *D="Great";
    char *E="Excellent!";
    char *F="Error!";
    if(score==0){
        return A;
    }else if(0<score&&score<60){
        return B;
    }else if(59<score&&score<80){
        return C;
    }else if(79<score&&score<100){
        return D;
    }else if(score==100){
        return E;
    }else{
         return F;
    }
}

int main (){
    printf("%c",*enshu_2_9(60));
    printf("%c",*(enshu_2_9(60)+1));
    
        printf("%c",*enshu_2_9(-1));
    printf("%c",*(enshu_2_9(-10)+1));

    return 0;
}