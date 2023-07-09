#include <stdio.h>

int main()
{
    long num = 0 ,mup = 1 ,sum = 0;
    scanf("%ld",&num);
    while(num)
    {
        if(num%2)
            sum = sum+mup*1;
        num/=10;
        mup*=10;
    }
    printf("%ld",sum);
    return 0;
}