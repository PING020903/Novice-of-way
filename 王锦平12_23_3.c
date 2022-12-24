/*求a + aa + aaa + aaaa + aaaaa + aa...a的值*/
#include<stdio.h>
int main()
{
	int num = 0, num_bit;
	int num_1 = 0;
	printf("打印a + aa + aaa + aaaa + aaaaa + aa...a的总和\n");
	printf("确认会有多少个a\n");
	scanf("%d", &num_bit);//确定有多少个数
	printf("请确认你的初始值\n");
	scanf("%d", &num);//确认初始值	
	num_1 = num;

	printf("初始值是 ： %d\n", num_1);
	//33333/3333=10······3	3333/333=10······3	333/33=10······3	33/3=10······3
	for (int i = 1; i < num_bit; i++)
	{
		num *= 10;
		num += 3;
		num_1 += num;
	}
	printf("总和： %d\n", num_1);
	return 0;
}