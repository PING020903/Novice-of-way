//右直角
#include<stdio.h>
#define RESET 'a'
int main()
{
	int  i;
	char in_put;
	printf("输入一个小写英文字符：\n");
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
			if (num <= i)
			{
				printf(" %c", num++);
			}				
		}

		//3、打印完一排换行
		printf("\n");
	}
	printf("\nEnd\n");;
	return 0;
}