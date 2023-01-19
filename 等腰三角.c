//等腰三角
#include<stdio.h>
#define RESET 'a'//初始值
int main()
{
	int  i;//行数
	char in_put;//输入的字符
	printf("输入一个小写英文字符，作为这个三角形底部的中心：");
	scanf("%c", &in_put);

	for (i = 'a'; i <= in_put; i++) //行数(循环条件)：i('行'初始值)等价于97，小于输入时，i++
	{
		//1、打印空格
		for (int j = 0; j < in_put - i; j++) //总行数in_put - 当前行数i；j小于输入-1时，j++
		{
			printf("  ");//只打印'字符'左边的空格
		}
		//2、打印字符
		char num = 'a';//num等价于97
		//左边部分
		for (int j = RESET; j < 2 * i + 1; j++) //2 * 当前行数i - 1；j小于（2*当前行数-1）时，j++
		{
			if (num <= i)//当前行数大于等于'a'
			{
				printf(" %c", num++);
			}
		}
		int num1 = i;//num1等价与'行'
		//右边部分
		for (int j = RESET; j < 2 * i + 1; j++)
		{
			if (num1 >= (in_put - i))//当前行数大于等于（输入-当前行数）
			{
				if (num1 == 'a')//若num1等于'a'，退出当前循环
					continue;
				else
					printf(" %c", --num1);
			}
		}
		//3、打印完一排换行
		printf("\n");
	}
	printf("\nEnd\n");
	getchar();
	getchar();
	return 0;
}