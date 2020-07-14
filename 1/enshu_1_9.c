#include <stdio.h>
#include <stdlib.h>
int enshu_1_9(int prize, int choice)
{
    if(prize==choice){
        int  ret=99;
        switch (prize)
        {
        case 0:
            return random()%2+1;
            break;  
        case 1:
            ret=random()%2;
            if(ret>=1){
                ret=2;
            }
            return ret;
            break;
        case 2:
            return random()%2;
            break;
        
        default:
            return -1;
            break;
        }
    }else{
        return prize;
    }
}
int main(void)
{
    int a=2;
    int b=2;
for (int i = 0; i < 10; i++)
{
  printf("%d",enshu_1_9(a,b));
  printf("\n");

}


 return 0;
}