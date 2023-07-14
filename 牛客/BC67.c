/*
牛牛尝试在蒙住眼睛的情况下拿到旁边的金币，假设的坐标是 (x,y) ，金币的坐标是 (x1,y1) ，
金币一定在牛牛在周围，即|x1-x|+|y1-y|=1 请你判断牛牛应该往哪个方向伸手。
*/


#include <stdio.h>
#include <math.h>

int main()
{
    int x = 0 ,y = 0;
    int x1 = 0 ,y1 = 0;
    scanf("%d %d",&x,&y);
    scanf("%d %d",&x1,&y1);
    if(1==abs(x1-x)+abs(y1-y))
    {
        if(x1>x)
            printf("r\n");
        else if(x1<x)
            printf("l\n");
        else if(y1>y)
            printf("u\n");
        else
            printf("d\n");
    }
    return 0;
}


