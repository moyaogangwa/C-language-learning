/*
今天牛牛学到了回文串，他想在数字里面找回文，即回文数，回文数是正着读与倒着读都一样的数，
比如1221，343是回文数，433不是回文数。请输出不超过n的回文数。
*/

#include <stdio.h>

int main()
{
    int n = 0 ,i = 0 ,j = 0 ,temp = 0;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        j=i;
        temp=0;
        while(j)
        {
            temp=temp*10+j%10;
            j/=10;
        }
        if(temp==i)
            printf("%d\n",i);
    }

    
    return 0;
}


