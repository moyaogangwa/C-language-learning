#include <stdio.h>

//��������

#define N 5
int main()
{
	int arr[N] = {0}, arr2[N] = {0}, flag = 1;
	int i = 0, j = 0, k = 0;
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	arr2[0]=arr[0];     //��arr��ȡ����һ����
	for(i=1;i<N;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]<arr[j])
			{
				for(k=i;k>=j;k--)       //������λ�ü�֮���Ԫ�غ���
				{
					arr2[k+1]=arr[k];
				}
				arr2[j]=arr[i];
				flag = 0;         
				break;
			}
		}
		if(1==flag)                    //���û�б���ȡ��������������򽫸�����������ֵ�����ұ�
		{
			arr2[i]=arr[i];
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");
	return 0;
}