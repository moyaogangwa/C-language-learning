/*
ţţ��һ�������죬����һ�����ն�Ӧ��Ӣ����
1������һ��Monday

2�����ڶ���Tuesday

3����������Wednesday

4�������ģ�Thursday

5�������壺Friday

6����������Saturday

7�������գ�Sunday
ţţ֪�����������ڼ�������������Ӣ��
*/


#include <stdio.h>


int main()
{
    char *pc[7]={"Monday","Tuesday","Wednesday","Thursday",\
                "Friday","Saturday","Sunday"};
    int input = 0;
    scanf("%d",&input);
    printf("%s\n",pc[input-1]);
    return 0;
}