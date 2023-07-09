#include <stdio.h>

//Ñî»ÔÈı½Ç2
int main()
{
    int arr[11][11]={0};
    int i = 0 ,j = 0;
    for(i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            if((1==i&&1==j)||i==j)
                arr[i][j]=1;
            else
            {
                arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
            }
        }
    }
    for(i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}