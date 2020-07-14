#include <stdio.h>
float enshu_1_7(float c)
{
c=(9.0/5.0)*c+32;
return c;
}
int main(void)
{
  printf("%f",enshu_1_7(-11.111111));
 return 0;
}