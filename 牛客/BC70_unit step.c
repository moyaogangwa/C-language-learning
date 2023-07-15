#include <stdio.h>

int main()
{
    int t = 0;
    while(scanf("%d",&t)!=EOF)
    {
        if(t>0)
            printf("%d\n",1);
        else if(t<0)
            printf("%d\n",0);
        else
            printf("%.1f\n",0.5);
    }
    return 0;
}

