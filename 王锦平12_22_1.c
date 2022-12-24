/*打印如下图案：
*			*
		   ***
		  *****
		   ***
			*
由用户自行输入确认行数
*/
#include<stdio.h>
int main()
{
	int in_put, i;
	printf("输入整数：\n");
	scanf("%d", &in_put);
	in_put /= 2;
	in_put += 1;
	//上半部分（大正三角形）：
	for (i = 1; i <= in_put; i++) //行数做循环条件
	{
		//1、打印空格
		for (int j = 0; j < in_put - i; j++) //总行数in_put - 当前行数i
		{
			printf(" ");//只打印*左边的空格
		}
		//2、打印*号
		for (int j = 0; j < 2 * i - 1; j++) //2 * 当前行数i - 1
		{
			printf("*");//要比空格多打
		}
		//3、没打印完一排换行
		printf("\n");
	}
	//下半部分（小倒三角形，比大正三角形少一行）
	for (i = 1; i <= (in_put - 1); i++)
	{
		for (int j = 0; j < i; j++)//j小于当前行数值-->循环打印
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * (in_put - 1 - i) + 1; j++)//2 * (上半部分行数in_put - 1 - 当前行数i) + 1	
		/*ps.(下半总行数-当前行数-1) * 2保证了循环的值是偶数，-1使输出的数是奇数*/
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");;
	return 0;
}