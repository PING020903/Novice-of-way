/*九九乘法表*/
#include<stdio.h>
int main()
{
	int x, y;
	for (x = 1; x < 10; x++)
	{
		for (y = 1; y < 10; y++)
		{
			printf("%3d * %d = %2d", x, y, x * y);
		}
		printf("\n");
	}
	return 0;
}