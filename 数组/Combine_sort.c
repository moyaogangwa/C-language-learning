#include <stdio.h>


//����2
#define N 5
#define M 5
int main()
{
	int arr1[N] = {0} ,arr2[M] = {0};
	int arr3[N+M] = {0} ,min = 0;
	int i = 0 ,j = 0 ,flag = 1 ,n1 = 0 ,n2 = 0;  //n1 n2�ֱ����arr1 arr2���м�����������arr3��
	printf("please input arr1[]:>>");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("please input arr2[]:>>");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr2[i]);
	}
	//��arr1 arr2 ת��Ϊ����
	if(arr1[0]>=arr1[N-1])
	{
		for(i=0;i<N/2;i++)
		{
			arr1[i]=arr1[i]^arr1[N-i-1];
			arr1[N-i-1]=arr1[i]^arr1[N-i-1];
			arr1[i]=arr1[i]^arr1[N-i-1];
		}
	}
	if(arr2[0]>=arr2[M-1])
	{
		for(i=0;i<M/2;i++)
		{
			arr2[i]=arr2[i]^arr2[M-i-1];
			arr2[M-i-1]=arr2[i]^arr2[M-i-1];
			arr2[i]=arr2[i]^arr2[M-i-1];
		}
	}
	//��arr1 arr2�е�ֵ���������arr3��
	for(i=0;n1!=N||n2!=M;i=n1)
	{
		flag = 1;
		if(n1!=N)           //��arr1�е�ֵû��ȫ������arr3
		{
			min = arr1[n1];
			for(j=n2;j<M;j++)
			{
				if(min>=arr2[j])        
				{
					arr3[n1+n2]=arr2[j];
					flag = 0;
					n2++;
					break;
				}
			}
			if(1==flag)
			{
				arr3[n1+n2]=min;
				n1++;
			}
		}
		else				//��arr1�Ѿ�ȫ������arr3��ֱ�Ӱ�����arr2��ʣ�µ�ֵ����arr3��
		{
			for(j=n1+n2;n2!=M;n2++)
			{
				arr3[n1+n2]=arr2[n2];
			}
		}
	}
	
	for(i=0;i<N+M;i++)
	{
		printf("%d ",arr3[i]);
	}
	printf("\n");
	return 0;
}



// ǿ��ѡ������
/*
#define N 5
#define M 5
int main()
{
	int arr1[N] = {0,2,5,9,10} ,arr2[M] = {1,3,4,6,9};
	int arr3[N+M] = {0} ,max = 0 ,index = 0;
	int i = 0, j = 0 ,temp = 0;
	for(i=0;i<N;i++)
	{
		arr3[i]=arr1[i];
	}
	for(i=0;i<M;i++)
	{
		arr3[i+N]=arr2[i];
	}

	for(i=0;i<N+M-1;i++)
	{
		max=arr3[0];
		index = 0;
		for(j=0;j<N+M-i;j++)
		{
			if(max<arr3[j])
			{
				max=arr3[j];
				index=j;
			}
		}
		temp = arr3[index];
		arr3[index] = arr3[N+M-1-i];
		arr3[N+M-1-i] = temp;
	}
	for(i=0;i<N+M;i++)
	{
		printf("%d ",arr3[i]);
	}
	printf("\n");
	return 0;
}
*/



