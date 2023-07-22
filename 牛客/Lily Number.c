/*
变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，
比如1461 可以拆分成（1和461）,（14和61）,（146和1),
如果所有拆分后的乘积之和等于自身，则是一个Lily Number。
*/

#include <stdio.h>

int main()
{
    int i = 0 , j = 0 ,sum = 0 ,n = 10;
    for(i=10000;i<100000;i++)
    {
        j=i;
        n=10;
        sum=0;
        while(j/n)
        {
            sum+=(j/n)*(j%n);
            n*=10;
        }
        if(i==sum)
            printf("%d ",i);
    }
    printf("\n");
    return 0;
}

