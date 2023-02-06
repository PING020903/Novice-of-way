//Page136
/*出口条件循环*/
#include<stdio.h>
int main()
{
	const int secret_code = 13;
	int code_entered;
	do 
	{
		printf("B才能退出循环\n");
		printf("现在请你输入一个整数：\n");
		scanf("%d", &code_entered);
	} while (code_entered != secret_code);
	printf("恭喜你退出了循环!!!\n");
	return 0;
}
