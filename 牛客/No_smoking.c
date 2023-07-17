/*Ban_smoking/ban_smoking -> No_smoking/no_smoking */

#include <stdio.h>
#include <string.h>
 
 
 int main()
 {
	int n = 0 ,i = 0 ,j = 0 ,l = 0;
	int ret = 0 ,k = 0;
	char refer[]={"an_smoking"};
	scanf("%d",&n);
	char str[n][100];
	for(i=0;i<n;i++)
		scanf("%s",str[i]);
	for(i=0;i<n;i++)
	{
		l=strlen(str[i]);
		for(j=0;j<l;j++)
		{
			if(str[i][j]=='b'||str[i][j]=='B')
			{
				ret=strncmp(&str[i][j+1],refer,10);
				if(0==ret)
				{
					strncpy(&str[i][j+1],"o_smoking",9);
					strcpy(&str[i][j+9],&str[i][j+10]);
					str[i][j]=str[i][j]+('n'-'b');
				}
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%s\n",str[i]);
	return 0;
 }