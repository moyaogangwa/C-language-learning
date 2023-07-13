/*
牛牛正在寄快递，他了解到快递在 1kg 以内的按起步价 20 元计算，
超出部分按每 kg 1元计算，不足 1kg 部分按 1kg计算。
如果加急的话要额外付五元，请问牛牛总共要支付多少快递费
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




