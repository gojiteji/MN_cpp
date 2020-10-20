#include<stdio.h>
#include<stdlib.h>
const long int a = 3399;
const long int b = 48271;
const long int c = 44488;
const long int d = 2147483647;

long long int rand2(long int *seed){
    long long int acc = (long long int)*seed%44488*48271-3399*((*seed)/44488);
    *seed = acc;//create next
    return acc;
}

void rand0(long int *j)
{
long int k = (*j) / c;
printf("b:%ld\n", (*j ));
*j = b * (*j - k * c) - a * k;
if (*j < 0)
*j += d; }




int main(){
    long int ss=100;
	long int *s=&ss;
	
	printf("%lld\n",rand2(s));


	return 0;
}
