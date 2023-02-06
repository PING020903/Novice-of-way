/*wheat.c——指数增长*/
#include<stdio.h>///唔係太理解*/
#define SQUARES 64//次方数
int main(void)
{
	const double CROP = 2E16;//世界小麦年产谷粒数
	double current, total;/*current现在的 total总数*/
	int count = 1;

	printf("square（方形格子）     grains（谷物）      total（总数）    ");
	printf("fraction of \n");
	printf("           added          grains    ");
	printf("world total（世界总量）\n");
	total = current = 1.0;//从1粒谷开始
	printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current;//下一个方形格子的谷粒翻倍
		total = total + current;//更新总数
		
		printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	}
	printf("这是全部");

	return 0;
}