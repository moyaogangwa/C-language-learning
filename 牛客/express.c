/*
ţţ���ڼĿ�ݣ����˽⵽����� 1kg ���ڵİ��𲽼� 20 Ԫ���㣬
�������ְ�ÿ kg 1Ԫ���㣬���� 1kg ���ְ� 1kg���㡣
����Ӽ��Ļ�Ҫ���⸶��Ԫ������ţţ�ܹ�Ҫ֧�����ٿ�ݷ�
*/


#include <stdio.h>

int main()
{
    float weight = 0.0 ,pay = 20.0;
    char ch = 0;
    scanf("%f %c",&weight,&ch);
    pay=pay+(ch=='y')*5;
    if(weight>0.1)
    {
        pay=pay+(weight-0.1);
    }
    printf("%d\n",(int)pay);
    return 0;
}




