#include<stdio.h>
#include<stdlib.h>
long long int rand2(long int *seed){
    long long int acc = (long long int)*seed ;
    *seed = acc ;
    return acc;}

int main(){
	long int * s=100;
	printf("%d",rand2(s));
	return 0;
}
