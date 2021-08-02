#include<stdio.h>
int main(){
	int year, month, day, i, sumDay=0;
	printf("please input year, month, day, eg: 2021/3/15\n");
	scanf("%d/%d/%d", &year, &month, &day);
	//计算天数
	int days[12]={31,0, 31,30,31,30,31,31,30,31,30,31};
	days[1]= ((year%400==0) || (year%100!=0 && year%4==0))?29:28; //二月
	//之前的月份天数累加
	for(i=0; i<month-1; i++){
		sumDay+=days[i];
	}
	sumDay+=day; //加上当月的天数
	printf("%d年%d月%d日是今年的第%d天\n", year, month, day, sumDay);
}
