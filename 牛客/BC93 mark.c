/*
����Ա�����ֳ���֡���7λ���٣��Ӽ�������������ɼ���ÿ��7���������ٷ��ƣ���
ȥ��һ����߷ֺ�һ����ͷ֣����ÿ���ƽ���ɼ���
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

