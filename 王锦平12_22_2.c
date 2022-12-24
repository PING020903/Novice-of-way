/*1 + 1/2 - 1/3 + 1/4 - 1/5 + 1/6...1/n，n由用户从键盘输入确认*/
#include <stdio.h>
int main()
{
	int in_put;
	double num = 0.0, num_a, num_b;

	printf("本程序的功能：");
	printf("1 + 1/2 - 1/3 + 1/4 - 1/5 + 1/6...1/n\n");
	printf("请输入整数n：");
	scanf("%d", &in_put);
	/*依题意，循环开始的初始值等于2，且不小于等于用户键入的整数*/
	for (int i = 2; i <= in_put; i++)
	{
		double a = 1 - (1.0 / (i + 1) );//计算出所有相加的数,'*''/'的优先级比'+''-'高
		num_a = a ;
		double b = 1.0 / i ;//计算出所有减的数
		num_b = b;		
	}
	/*printf("%.8f", num_a);*/
	num =   num_b + num_a;
	printf("\n结果为：%.8f", num);
	return 0;
}