/*
KiKi想知道已经给出的三条边a，b，c能否构成三角形，如果能构成三角形，
判断三角形的类型（等边三角形、等腰三角形或普通三角形）。
*/


#include <stdio.h>

int main()
{
    float a = 0.0 ,b = 0.0 ,c = 0.0;
    while(scanf("%f %f %f",&a,&b,&c)!=EOF)
    {
        if(a+b>c && a+c>b && b+c>a)
        {
           if(a==b&&a==c)
                printf("Equilateral triangle!\n");
            else if(a==b||a==c||b==c)
                printf("Isosceles triangle!\n");
            else
                printf("Ordinary triangle!\n");
        }
        else 
        {
            printf("Not a triangle!\n");
        }
    }
    return 0;
}