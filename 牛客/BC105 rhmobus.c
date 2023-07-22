/*
 ‰»Î£∫
2
 ‰≥ˆ£∫
  * 
 * * 
* * * 
 * * 
  * 

*/

#include <stdio.h>

int main()
{
    int n = 0 ,i = 0 , j = 0;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=2*n;i++)
        {
            for(j=0;j<=2*n;j++)
            {
                if(i<=n&&j>=n-i&&j<=n+i || i>n&&j>=n-(2*n-i)&&j<=n+(2*n-i))
                {
                    printf("* ");
                    j++;
                }
                else 
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

