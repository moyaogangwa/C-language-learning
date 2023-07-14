/*
牛牛的通勤路上有两种选择，要么走路，要么打车，
牛牛走路的速度是 1m/s 。打车的速度的 10m/s ，但是打车需要等出租车 10 s，
请你计算牛牛想尽快到公司应该选择打车还是走路。
*/


#include <stdio.h>

int main()
{
    int dist = 0 ,t1 = 0 ,t2 = 0;
    scanf("%d",&dist);
    if(dist<=10)
        printf("w\n");
    else
        printf("v\n");
    return 0;
}

