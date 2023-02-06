/*skiptwo.c——跳过输入中的前两个整数*/
#include<stdio.h>
int main(void)
{
	int n;

	printf("请输入三个整数：\n");
	scanf("%d %d %d", &n);/*无论如何都只会读取最后的整数，因为前面输入的被后面输入的覆盖了*/
	printf("最后的一个整数是%d\n", n);

	return 0;
}