/*
公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），
去掉一个最高分和一个最低分，输出每组的平均成绩。
*/

#include <stdio.h>

int main()
{
    int max = 0 ,min = 0;
    int arr[7] = {0} ,i = 0;
    float ave = 0.0;
    while(scanf("%d",&arr[i])!=EOF)
    {
        if(0==i)
        {
            min=max=arr[i];
        }
        if(max<arr[i])
            max=arr[i];
        else if(min>arr[i])
            min=arr[i];
        ave+=arr[i];
        i++;
        if(7==i)
        {
            ave=(ave-max-min)/5.0;
            printf("%.2f\n",ave);
            ave=0;
            i=0;
        }
    }
    return 0;
}

