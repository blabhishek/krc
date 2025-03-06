/* EX 5-9
 * Rewrite the routines day_of_year and month_day with
 * pointers instead of indexing.
 */
#include<stdio.h>
// days in leap and normal year
static char month_days[2][13] =
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int dayofmonth(int year,int yearday,int *pmonth,int *pday);
int dayofyear(int year,int day,int month);
int main(void)
{
	int month,day,year;
	int yearday;
	printf("Enter day,month,year\n");
	scanf("%d%d%d",&day,&month,&year);
	printf("Day of the year = %d\n",dayofyear(year,day,month));

	printf("Enter yearday,and year\n");
	scanf("%d%d",&yearday,&year);
	dayofmonth(year,yearday,&month,&day);
	printf("month - %d\t day - %d\n",month,day);
}
int dayofyear(int year,int day,int month)
{
	int i,leap;
	char *p;
	if(year < 1752 || month < 1 || month > 12 || day < 1)
		return -1;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if(day > month_days[leap][month])
		return -1;
	p = &month_days[leap][1];
	for(i = 1; i < month; i++,p++)
		day += *p;
	return day;
}
int dayofmonth(int year,int yearday,int *pmonth,int *pday)
{
	int i,leap;
	char *p;
	if (year < 1752 || yearday < 1)
		return -1;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if((leap && yearday > 366) || (!leap && yearday > 365))
		return -1;
	p = &month_days[leap][1];
	for(i = 1; yearday > *p; i++,p++)
		yearday -= *p;
	*pmonth = i;
	*pday = yearday;
}
