/*
ţţ��������ס�۾���������õ��ԱߵĽ�ң������������ (x,y) ����ҵ������� (x1,y1) ��
���һ����ţţ����Χ����|x1-x|+|y1-y|=1 �����ж�ţţӦ�����ĸ��������֡�
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


