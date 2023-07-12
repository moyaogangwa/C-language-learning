#include <stdio.h>
#define N 3

typedef struct student
{
	int math;
	int C;
	float average;
	char *name;
}Stu;

int main()
{
	int i = 0 ,index = 0;
	float max = 0.0;
	Stu score[N]=
	{
		{.name="zhangsan"},
		{.name="lisi"},
		{.name="wangwu"}
	};
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&score[i].math,&score[i].C);
		score[i].average=(score[i].math+score[i].C)*1.0/2;
	}
	max=score[0].average;
	for(i=0;i<N;i++)
	{
		if(max<score[i].average)
		{
			max=score[i].average;
			index=i;
		}
	}
	printf("max average:%.2f\n",max);
	printf("student:\n");
	printf("name:%s\nmath:%d C:%d\n",score[index].name,score[index].math,score[index].C);
	return 0;
}