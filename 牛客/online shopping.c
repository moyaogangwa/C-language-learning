/*
KiKi非常喜欢网购，在一家店铺他看中了一件衣服，他了解到，
如果今天是“双11”（11月11日）则这件衣服打7折，
“双12” （12月12日）则这件衣服打8折，
如果有优惠券可以额外减50元（优惠券只能在双11或双12使用），求KiKi最终所花的钱数。
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




