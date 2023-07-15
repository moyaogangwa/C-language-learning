/*
牛牛的一周有七天，从周一到周日对应的英文是
1、星期一：Monday

2、星期二：Tuesday

3、星期三：Wednesday

4、星期四：Thursday

5、星期五：Friday

6、星期六：Saturday

7、星期日：Sunday
牛牛知道今天是星期几，请输出这天的英文
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