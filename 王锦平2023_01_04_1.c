/*写一个程序将一个字符串循环右移n位
例如：字符串abcdef 循环右移2位是 efabcd*/
#include<stdio.h>
#include<string.h>
int main()
{
	printf("将对以下字符串进行右移-->");
	char ch[1024] = "abcdef\0";
	unsigned int num = 0;
	printf("%s\n", ch);
	printf("输入右移的位数：");
	scanf("%d", &num);
	num %= strlen(ch);
	if (num == 0)
		printf("after--->%s", ch);
	else
	{
		printf("after--->");
		for (int i = num; i < strlen(ch); i++)
			printf("%c", ch[i]);
		for (int i = 0; i < num; i++)
			printf("%c", ch[i]);
	}
	/*printf("after--->%s\n", ch);*/
	
	//printf("\n%d", ' ');
	return 0;
}