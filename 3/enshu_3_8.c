#include <stdio.h>

void enshu_3_8(char **argv, char *buffer)
{
    int i, j, cnt = 0;
    for(i = 0;*(argv + i) != NULL;i++){
        for(j = 0;*(*(argv + i) + j) != '\0';j++){
            *(buffer + cnt) = *(*(argv + i) + j);
            cnt++;
        }
    }
    *(buffer + cnt) = '\0';
}