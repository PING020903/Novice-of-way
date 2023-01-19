//自己调用自己
//用递归完成int fun(int n)
//{
//	return fun(n-1)+fun(n-2)
//}
#include<stdio.h>
int fun(int n)
{
	n += (n - 1);
	printf("\n被递归后：%d", n);
	return fun(n);
	//n = n * (n - 1);
}
int main()
{
	int i;
	printf("请输入一个将要被递归的整数：");
	scanf("%d", &i);
	fun(i);
	return 0;
}