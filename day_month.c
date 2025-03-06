#include<stdio.h>
static char month_days[2][13] =
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
void dayofmonth(int year,int yearday,int *pmonth,int *pday);
int dayofyear(int year,int day,int month);
int main(void)
{
	int month,day,year;
	printf("Enter day,month,year\n");
	scanf("%d%d%d",&day,&month,&year);
	printf("day of the year = %d",dayofyear(year,day,month));
}
int dayofyear(int year,int day,int month)
{
	int i,leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for(i = 1; i < month; i++)
		day += month_days[leap][i];
	return day;
}
void dayofmonth(int year,int yearday,int *pmonth,int *pday)
{
	int i,leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for(i = 1; yearday > month_days[leap][i]; i++)
		yearday -= month_days[leap][i];
	*pmonth = i;
	*pday = yearday;
}
