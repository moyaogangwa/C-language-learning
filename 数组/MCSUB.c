#include <stdio.h>


//�������������֮��(�±�����)

#define N 5
int main()
{
	int arr[N] = {0} ,n = 0;             //n�洢���������и����ĸ���
	int i = 0 ,j = 0 ,left = -1 ,right = -1;
	int sum = 0 ,max = 0 ,temp = 0; 
	
	//��������,���������������и����ĸ���
	printf("please input:>>");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]<0)
			n++;
	}
	
	//���ȫΪ����
	if(N==n)
	{
		max=arr[0];
		for(i=0;i<N;i++)
		{
			arr[i]>max?arr[i]:max;
		}
		printf("max son list:%d ",max);
	}
	
	//�����ȫΪ����
	else
	{
		for(i=0;i<N;i++)
		{
			if(arr[i]<0 && 0==sum)      //�����һ��ֵΪ����������
				continue;
			else if(arr[i]>0 && 0==sum)  
				left=i;
			else if(arr[i]<0 && 0!=sum)  //�������sum;������arr[i]<0
			{
				for(j=i+1;arr[j]>=0 && j<N;j++)
				{
					temp += arr[j];       //�����������ĸ�������һ������֮���������ĺ�
				}
				if(sum+temp+arr[i]<temp)  //�������ӵ���һ��������ֵ��temp���бȽ�
				{
					max = sum = temp;
					left = i+1;
					i=j-1;
					continue;
				}
			}
			
			sum+=arr[i];
			if(max<=sum)
			{
				max = sum;
				right=i;
			}
		}
		
		printf("max son list:");
		for(i=left;i<=right;i++)
		{
			printf("%d ",arr[i]);
		}
	}
	printf("max value:%d\n",max);
	return 0;
}







