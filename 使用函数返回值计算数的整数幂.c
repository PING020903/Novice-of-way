//Page143
/*使用函数返回值的循环示例*/
#include<stdio.h>
double power(double n, int p)/*需要被乘的数n，整数次幂p*/
{
	double pow = 1;
	int i;
	for (i = 1; i <= p; i++)
	{
		pow *= n;
	}
	return pow;//返回pow的值
}
int main()
{
	double x, xpow;
	int exp;

	printf("确认一个数和它的整数次幂\n");
	printf("按q退出\n");
	while (scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);//函数调用，将计算结果返回给主调函数
		printf("%.3g 经过 %d 次幂运算后是 %.5g\n", x, exp, xpow);
		printf("确认下一对数字或“q”退出\n");
	}
	printf("希望我已经明白了。");
	return 0;
}
//输入2 10，scanf()成功读取两值，并返回2循环继续
//输入q会使得scanf()的返回值为0，因为与转换说明%lf不匹配
//编译器需要知道double power()函数返回值的类型，才能指定有多少字节的数据，以及如何解答它们
//