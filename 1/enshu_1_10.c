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

int enshu_1_10(int total_loop){
long int counter=0;
for (int i = 0; i < total_loop; i++)
{   
  int   prize=random()%3;
 int   choice=random()%3;
if(   enshu_1_9(prize,choice)==prize){
    counter++;
}else{
}
}
return counter;
}

int main(void)
{

  printf("%d",enshu_1_10(100000));
  printf("\n");

 return 0;
}