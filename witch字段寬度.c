/*width.c字段宽度*/
#include<stdio.h>
#define PAGES 959
int main(void)
{
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);
	printf("*%8d*\n", PAGES);
	printf("%99.6d\n", PAGES);

	return 0;
}