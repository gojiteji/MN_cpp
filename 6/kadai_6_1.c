#include <stdio.h>

long long int rand2(long int *seed)
{
 long long int acc = (long long int)*seed*48271LL;
 *seed = acc%2147483647;
 return acc;
}


int main(void){
    // Your code here!
    
}
