/*
����ˮ�ɻ��� - Lily Number������������֣����м��ֳ��������֣�
����1461 ���Բ�ֳɣ�1��461��,��14��61��,��146��1),
������в�ֺ�ĳ˻�֮�͵�����������һ��Lily Number��
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

