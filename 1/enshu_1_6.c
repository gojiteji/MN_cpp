#include <stdio.h>
float enshu_1_6(float f)
{
f=(5.0/9.0)*(f-32.0);
return f;
}
int main(void)
{
  printf("%f",enshu_1_6(12));
 return 0;
}