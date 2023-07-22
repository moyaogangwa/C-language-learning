/*
多组输入，一个整数（2~20），表示金字塔边的长度，即“*”的数量，，也表示输出行数。
输入：
4
输出：
   * 
  * * 
 * * * 
* * * * 

*/

#include <stdio.h>

int main()
{
    int n = 0 ,i = 0 ,j = 0;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<2*n-1;j++)
            {
                if(j>=n-1-i&&j<=n-1+i)
                {
                    printf("* ");
                    j++;
                }
                else
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}


