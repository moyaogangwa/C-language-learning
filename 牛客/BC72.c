/*
ţţ��һ��ѧϰ�ƻ������ƻ��� y �� m �� d �տ�ʼѧϰ��
����֮ǰ���Ǿ����Ὺʼѧϰ�ģ�������һ����ʼѧϰ�Ͳ���ͣ������
�����ж� y1 �� m1 �� d1 ��ţţӦ��ѧϰ��
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