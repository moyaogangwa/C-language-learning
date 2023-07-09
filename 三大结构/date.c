#include <stdio.h>




//计算某年已过天数
int days(int year ,int month,int today)
{
	int refer = 0 ,day = 0;
	refer=((0==year%4)&&(0!=year%100) || (0==year%400))?1:0;
	switch(month-1)
	{
		case 12:
			day+=31;
		case 11:
			day+=30;
		case 10:
			day+=31;
		case 9:
			day+=30;
		case 8:
			day+=31;
		case 7:
			day+=31;
		case 6:
			day+=30;
		case 5:
			day+=31;
		case 4:
			day+=30;
		case 3:
			day+=31;
		case 2:
			day+=28+refer;
		case 1:
			day+=31;
			break;
		default:
			return -1;
	}
	day=day+today;
	return day;
}

int main()
{
	int year = 0,month=0,today=0,day=0,refer_m=0;       //day存放今年已过天数
	int year_b=0,month_b=0,today_b=0,day_b=0,refer_b=0;   //day_b存放生日当年已过天数
	int dif_value=0;                 //存放今年与生日之间间隔的年数
	
	//输出今年已过天数
	printf("please input:>>");
	scanf("%d%d%d",&year,&month,&today);
	day=days(year,month,today);
	printf("all day: %d\n",day);
	
	printf("please input birthday:>>");
	scanf("%d%d%d",&year_b,&month_b,&today_b);
	refer_b=((0==year_b%4)&&(0!=year_b%100) || (0==year_b%400))?1:0;   //判断出生年份是否为闰年
	day_b=days(year_b,month_b,today_b);
	(refer_b==1)?(day=day+366-day_b):(day=day+365-day_b);              //计算出生后当年剩余天数
	
	//计算今年与生日之间间隔的年份的总天数
	dif_value=year-year_b-1;
	for(int i = 1;i<=dif_value;i++)
	{
		refer_m=((0==(year-i)%4)&&(0!=(year-i)%100) || (0==(year-i)%400))?1:0;
		(refer_m==1)?(day+=366):(day+=365);
	}
	
	printf("It's %d days since you were born\n",day);
	
	return 0;
}