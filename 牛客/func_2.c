/*
�Ӽ�������a, b, c��ֵ����̼��㲢���һԪ���η���ax2 + bx + c = 0�ĸ���
��a = 0ʱ�������Not quadratic equation������a �� 0ʱ�����ݡ� = b2 - 4*a*c������������㲢������̵ĸ�
*/

#include <stdio.h>
#include <math.h>

int func_2(float a,float b,float c,float*x1,float*x2)
{
    float d = 0.0;
    d=b*b-4*a*c;
    if(0==d)
    {
        if(0.0==b&&a>0.0)
            b=-b;
        *x1=*x2=(-b)/(2*a);
        return 0;
    }
    else if(d>0)
    {
        *x1=(-b-sqrt(d))/(2*a);
        *x2=(-b+sqrt(d))/(2*a);
        return 1;
    }
    else 
    {
        *x1=(-b)/(2*a);
        *x2=sqrt(-d)/(2*a);
        return 2;
    }
}

int main()
{
    float a = 0 ,b = 0 ,c = 0;
    float x1 = 0.0 ,x2 = 0.0;
    int ret = -1;
    while( scanf("%f %f %f",&a,&b,&c)!=EOF)
    {
        if(0==a)
        {
            printf("Not quadratic equation\n");
        }
        else 
        {
            ret = func_2(a,b,c,&x1,&x2);
        }
        switch(ret)
        {
            case 0:
                printf("x1=x2=%.2f\n",x1);
                break;
            case 1:
                printf("x1=%.2f;x2=%.2f\n",x1,x2);
                break;
            case 2:
                printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n",x1,x2,x1,x2);
                break;
        }
    }
    return 0;
}