#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *enshu_4_5(char **argv)
{
    int i, j, cnt=0;
    for(i = 0;*(argv + i) != NULL;i++){
        for(j = 0;*(*(argv + i) + j) != '\0';j++) cnt++;
    }

    char *buffer = malloc(sizeof(char) * (cnt + 1));
    char *x;
    if (buffer != NULL) {
        x = buffer;
        for(i = 0;*(argv + i) != NULL;i++){
            for(j = 0;*(*(argv + i) + j) != '\0';j++){
                *x = *(*(argv + i) + j);
                x++;
            }
        }
        *x = '\0';
        return buffer;
    
    }else {
        return NULL;
    }

}