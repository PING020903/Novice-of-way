/*功能：写一个函数，将你键入的任意字符串逆序存放（要求用指针操作）*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//将交换封装在函数中因为是局部临时变量，会被栈释放，需要申请堆空间来暂时存放
//字符串逆序存放
int exchange(char* your_strings)//字符串该用指针形参
{
	char* q = your_strings;
	int j = 1;
	int num = strlen(q);
	for (int i = 0; i < strlen(your_strings) / 2; i++)//需要调换的次数 係字符总数的 一半
	{
		//异或交换value
		*(q + i) ^= q[num - j];
		q[num - j] ^= *(q + i);
		*(q + i) ^= q[num - j];
		j++;//每次交换以后，增加从后面倒着数的次数
	}
	
	q = malloc(num);
	free(q);
	return *q;
}
int main()
{
	char ch[1024] = { 0 };
	printf("请确认您需要逆序的字符串：");
	scanf("%s", &ch);
	printf("\n请确认您的字符串：%s", ch);
	getchar();

	exchange(ch);
	printf("\n字符串结果：%s", ch);
	return 0;
}