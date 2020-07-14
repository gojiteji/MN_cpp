#include <stdio.h>
int enshu_1_8(int y)
{
int ret=0;
if(y%4==0){
ret=1;
	if(y%100==0){
	ret=0;
		if(y%400==0){
		ret=1;
		}
	}

}
return ret;

}
int main(void)
{
  printf("%d",enshu_1_8(2020));
 return 0;
}