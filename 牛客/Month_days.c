/*
KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
*/

#include <stdio.h>

int Month_days(int m ,int fg)
{
    if(m>0&&m<=12)
    {
        switch(m)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
                break;
            case 2:
                return 28+fg;
                break;
            default:
                return 30;
                break;
        }
    }
    else
        return -1;
}

int main()
{
    int year = 0 ,month = 0 ,days = 0;
    int flag = 0;
    while(scanf("%4d %d",&year,&month)!=EOF)
    {
        flag = 0;
        if((0==year%4&&0!=year%100)||(0==year%400))
            flag=1;
        days=Month_days(month,flag);
        printf("%d\n",days);
    }
    return 0;
}