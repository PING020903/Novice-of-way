/*LIVE*/
#include<stdio.h>
void fuck(void);
void you();/*分配函数*/
int/*声明整数类型*/ year, age, live;/*函数分配与函数返回值定义无先后顺序之分*/
int main(void)/*规定main后跟主程序*/
{
	age = 18;
	year = 356;
	live = age * year;
	
	
	fuck();
	you();
	printf("\n\n按任意键退出");

	getchar();
	return 0;
}
void fuck(void) /*函数定义*/
{
	you();
}
void you(void)
{
	getchar();
	printf("下午好！");
	getchar();
	printf("\nmy age is %d.\n", age);
	printf("there are %d days in a day.\n", year);
	printf("live=%d\n", live);
}
 
 
 