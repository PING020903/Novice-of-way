/*，实现求小于等于给定n(范围0-100000)的整数范围内,所有能被6整除或者数字中含有6的整数个数，并把符合要求的整教打印出来*/
#include<stdio.h>
/*用取余，将所有位数中带有6的数单独取出*/
int six(int a)
{
	int number_1, number_2, number_3, number_4, number_5;
	number_1 = a % 10;//个位
	number_2 = number_1 % 10;//十位
	number_3 = number_2 % 10;//百位
	number_4 = number_3 % 10;//千位
	number_5 = number_4 % 10;//万位
	if (number_1 == 6 || number_2 == 6 || number_3 == 6 || number_4 == 6 || number_5 == 6 )
	{
		printf("包含6的数：%d\n", a);
	}
	return 1;
}
int main()
{
	int n = 0, i = 0;
	int number = 0;
	for (n = 0; n < 100000; n++)
	{
		/*++i，先加再用*/
		++i;
		i %= 6;
		/*因为起始数是0，故此要预先+1*/
		six(n + 1);
		if (i == 0)
		{
			/*此处n+1亦是同类*/
			printf("n:%d\n", n+1);
			number++;
		}
	}
	printf("这些都是能被6整除的数");
	printf("能被6整除的数一共有：%d\n", number);
	return 0;
	
}