/*
KiKi�ǳ�ϲ����������һ�ҵ�����������һ���·������˽⵽��
��������ǡ�˫11����11��11�գ�������·���7�ۣ�
��˫12�� ��12��12�գ�������·���8�ۣ�
������Ż�ȯ���Զ����50Ԫ���Ż�ȯֻ����˫11��˫12ʹ�ã�����KiKi����������Ǯ����
*/


#include <stdio.h>

int main()
{
    float val = 0.0 ,pay = 0.0;
    int month = 0 ,date = 0 ,coupon = 0;
    scanf("%f%2d%2d%d",&val,&month,&date,&coupon);
    if(11==month&&11==date)
        pay=val*0.7-coupon*50;
    else if(12==month&&12==date)
        pay=val*0.8-coupon*50;
    else
        pay=val;
    if(pay<0)
        pay=0;
    printf("%.2f\n",pay);
    return 0;
}




