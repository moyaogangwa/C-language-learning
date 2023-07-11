#include <stdio.h>

int main()
{
    float weight =0.0 ,height = 0.0 ,BIM = 0.0;
    printf("please input(w h):>>");
    scanf("%f %f",&weight,&height);
    BIM=weight/(height*height);
    if(18.5<=BIM&&BIM<=23.9)
        printf("Your BIM:%.2f ,Normal\n",BIM);
    else
        printf("Your BIM:%.2f ,Abnormal\n",BIM);
    return 0;
}