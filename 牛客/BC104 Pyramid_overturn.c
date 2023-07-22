/*
 ‰»Î£∫
5
 ‰≥ˆ£∫
* * * * * 
 * * * * 
  * * * 
   * * 
    * 

*/

#include <stdio.h>

int main()
{
    int n = 0 ,i = 0 ,j = 0 ;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<2*n-1;j++)
            {
                if(j>=n-1-i&&j<=n-1+i)
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

