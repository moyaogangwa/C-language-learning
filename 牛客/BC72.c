/*
牛牛有一个学习计划，他计划在 y 年 m 月 d 日开始学习，
但在之前他是绝不会开始学习的，但是他一旦开始学习就不会停下来，
请你判断 y1 年 m1 月 d1 日牛牛应该学习吗。
*/

#include <stdio.h>

int main()
{
    int year = 0 ,month = 0 ,date = 0;
    int year1 = 0 ,month1 = 0 ,date1 = 0;
    scanf("%4d %d %2d",&year,&month,&date);
    scanf("%4d %d %2d",&year1,&month1,&date1);
    if(year1>year)
        printf("yes\n");
    else if(year1==year&&((month1>month)||(month1==month&&date1>=date)))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}