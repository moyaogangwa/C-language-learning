#include <stdio.h>

#define N 5

typedef struct bookcase  //ͼ�������
{
	char *n;
	char *book[2];       
}Bookc;

typedef struct library   //ͼ���
{
	char *name;
	char *rg_name[N];
	Bookc *rg;
}lib;

int main()
{
	int i = 0 ,input = 0;
	lib my_lib={
				.name="baolong library",
				.rg_name={"cartoon","sci_fi","prose","history","poetry"}
				};
	Bookc segment[N]={
						{.n="cartoon",.book={"douluo","daerduotutu"}},
						{.n="sci_fi",.book={"santi","liulangdiqiu"}},
						{.n="prose",.book={"zhaohuaxishi","beiying"}},
						{.n="history",.book={"shiji","hanshu"}},
						{.n="poetry",.book={"shijing","chuci"}},
					  };
	
	printf("%s\n",my_lib.name);
	for(i=0;i<N;i++)
		printf("%s(%d) ",my_lib.rg_name[i],i);
	
	printf("\nplease choose:>");  //���ݱ��ѡ������
	scanf("%d",&input);
	my_lib.rg=segment+input;
	
	for(i=0;i<2;i++)
		printf("%s ",(*my_lib.rg).book[i]);  //������������ɵ��鼮
	printf("\n");
	return 0;
}

