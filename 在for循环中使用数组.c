//Page141
/*使用循环处理数组*/
#include<stdio.h>
#define SIZE 10
#define PAR 72
int main()
{
	int index, score[SIZE];
	int sum = 0;
	float average;

	printf("enter %d golf scores:\n", SIZE);
	for (index = 0; index < SIZE; index++)
	{
		scanf("%d", &score[index]);
	}
	printf("the scores read in are as follows:\n");
	for (index = 0; index < SIZE; index++)
		printf("%5d", score[index]);
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		sum += score[index];
	}
	average = (float)sum / SIZE;
	printf("sum of scores = %d, average = %.2f\n", sum, average);
	printf("that is a handicap of %.0f.\n", average - PAR);
	return 0;
}
//只读前面输入的10个整数，scanf()会跳过空白字符
//使用#define SIZE创建明示的常量来指定数组的大小，以后要修改范围只需要修改SIZE
//设置正确的数组边界很重要，第一个元素的下标是0
//程序能重复现实刚读入的数据，是一个很好的习惯，有助于确保程序处理的数据与期望相符
//模块化原则：把程序划分为一些独立的单元，方便后续更新或修改程序