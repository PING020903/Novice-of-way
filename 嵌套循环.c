//Page138
/*使用嵌套循环*/
#include<stdio.h>
#define ROWS 6
#define CHARS 10
int main()
{
	int row;
	char ch;
	for (row = 0; row < ROWS; row++)
	{
		for (ch = 'A'; ch < ('A' + CHARS); ch++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	return 0;
}
//嵌套循环中的内层循环 在每次外层循环迭代时 执行完所有的循环